#include "catch/catch.hpp"
#include "util/track-and-hold.h"

TEST_CASE("Track and Hold") {
  constexpr float initial_value{93.f};
  float source{initial_value};
  auto supplier = [&source] { return source; };
  DHE::TrackAndHold tracker{supplier};

  SECTION("newly constructed") {

    SECTION("tracks the supplier") {
      source += 19;

      REQUIRE(tracker.value() == supplier());
    }
  }

  SECTION("while tracking") {
    tracker.track();

    SECTION("yields the supplier's value") {
      source += 1;
      REQUIRE(tracker.value() == supplier());
    }
  }

  SECTION("while holding") {
    constexpr float value_at_hold{543.f};
    source = value_at_hold;
    tracker.hold();

    source += 1;

    SECTION("yields the value held on entering holding mode") {
      REQUIRE(tracker.value() == value_at_hold);
    }

    SECTION("does not track the supplier") {
      REQUIRE(tracker.value() != supplier());
    }
  }
}