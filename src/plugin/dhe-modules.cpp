#include "rack.hpp"
#include "dhe-modules.h"
#include "stage/stage-widget.h"
#include "stage/stage.h"

rack::Plugin *plugin;

void init(rack::Plugin *p) {
  plugin = p;
  p->slug = DHE::MANUFACTURER;
  p->version = TOSTRING(VERSION);
  p->website = "https://github.com/dhemery/DHE-Modules";
  p->manual = "https://github.com/dhemery/DHE-Modules/wiki";

  p->addModel(rack::createModel<DHE::StageWidget>(DHE::MANUFACTURER, DHE::Stage::SLUG, DHE::Stage::NAME,
                                                  rack::ENVELOPE_GENERATOR_TAG));
}

namespace DHE {
const Range NORMAL{0.0f, 1.0f};
const Range BIPOLAR_NORMAL{-1.0f, 1.0f};
const Range UNIPOLAR_VOLTAGE{0.0f, 10.0f};
const Range BIPOLAR_VOLTAGE{-5.0f, 5.0f};
}