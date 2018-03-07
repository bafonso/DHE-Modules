#include "dhe-modules.h"

#include "gui/booster-stage-widget.h"
#include "gui/hostage-widget.h"
#include "gui/stage-widget.h"
#include "gui/swave-widget.h"
#include "gui/upstage-widget.h"
#include "modules/booster-stage-module.h"
#include "modules/hostage-module.h"
#include "modules/stage-module.h"
#include "modules/swave-module.h"
#include "modules/upstage-module.h"

rack::Plugin *plugin;

namespace DHE {
template<typename TModel, typename TWidget, typename... TTag>
static rack::Model *createModel(std::string moduleSlug, TTag... tags) {
  return rack::Model::create<TModel, TWidget>("DHE-Modules", moduleSlug, moduleSlug, tags...);
}
}

void init(rack::Plugin *p) {
  plugin = p;

  p->slug = "DHE-Modules";
  p->version = TOSTRING(VERSION);
  p->website = "https://github.com/dhemery/DHE-Modules";
  p->manual = "https://github.com/dhemery/DHE-Modules/wiki";

  p->addModel(modelBoosterStage);
  p->addModel(modelHostage);
  p->addModel(modelStage);
  p->addModel(modelSwave);
  p->addModel(modelUpstage);
}

rack::Model
    *modelBoosterStage = DHE::createModel<DHE::BoosterStageModule, DHE::BoosterStageWidget, rack::ModelTag>("Booster Stage", rack::ENVELOPE_GENERATOR_TAG);
rack::Model *modelHostage = DHE::createModel<DHE::HostageModule, DHE::HostageWidget, rack::ModelTag>("Hostage", rack::ENVELOPE_GENERATOR_TAG);
rack::Model *modelStage = DHE::createModel<DHE::StageModule, DHE::StageWidget, rack::ModelTag>("Stage", rack::ENVELOPE_GENERATOR_TAG);
rack::Model *modelSwave = DHE::createModel<DHE::SwaveModule, DHE::SwaveWidget, rack::ModelTag>("Swave", rack::WAVESHAPER_TAG);
rack::Model *modelUpstage = DHE::createModel<DHE::UpstageModule, DHE::UpstageWidget, rack::ModelTag>("Upstage", rack::ENVELOPE_GENERATOR_TAG);
