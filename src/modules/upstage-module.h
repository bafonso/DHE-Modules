#pragma once

#include <algorithm>

#include "module.h"
#include "util/controls.h"
#include "util/range.h"

namespace DHE {

struct UpstageModule : Module {
  UpstageModule() : Module{PARAMETER_COUNT, INPUT_COUNT, OUTPUT_COUNT} {}

  bool is_waiting() const {
    return std::max(inputs[WAIT_IN].value, gate_button(WAIT_BUTTON)) > 0.5f;
  }

  float stage_out() const {
    const auto &range = Level::range(params[LEVEL_SWITCH].value);
    auto rotation = modulated(LEVEL_KNOB, LEVEL_CV);
    return Level::scaled(rotation, range);
  }

  void step() override {
    outputs[TRIG_OUT].value = trigger_out();
    outputs[STAGE_OUT].value = stage_out();
  }

  float trigger_in() const {
    return std::max(inputs[TRIG_IN].value, gate_button(TRIG_BUTTON));
  }

  float trigger_out() const {
    return is_waiting() ? 0.f : trigger_in();
  }

  enum ParameterIds {
    LEVEL_KNOB,
    TRIG_BUTTON,
    WAIT_BUTTON,
    LEVEL_SWITCH,
    PARAMETER_COUNT
  };
  enum InputIds {
    TRIG_IN,
    WAIT_IN,
    LEVEL_CV,
    INPUT_COUNT
  };
  enum OutputIds {
    TRIG_OUT,
    STAGE_OUT,
    OUTPUT_COUNT
  };
};

}