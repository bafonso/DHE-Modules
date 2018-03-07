#include <componentlibrary.hpp>

#include "modules/hostage-module.h"
#include "hostage-widget.h"

namespace DHE {

struct HostagePort : rack::SVGPort {
  HostagePort() {
    background->svg = rack::SVG::load(rack::assetPlugin(plugin, "res/hostage/port.svg"));
    background->wrap();
    box.size = background->box.size;
  }
};

struct HostageKnobLarge : rack::RoundKnob {
  HostageKnobLarge() {
    setSVG(rack::SVG::load(rack::assetPlugin(plugin, "res/hostage/knob-large.svg")));
    box.size = rack::Vec(39.f, 39.f);
  }
};

struct HostageSwitch3 : rack::SVGSwitch, rack::ToggleSwitch {
  HostageSwitch3() {
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/hostage/switch-3-low.svg")));
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/hostage/switch-3-mid.svg")));
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/hostage/switch-3-high.svg")));
  }
};

HostageWidget::HostageWidget(rack::Module *module) : ModuleWidget(module, 5, "res/hostage/panel.svg") {
  auto widget_right_edge = width();

  auto left_x = width()/4.f + 0.333333f;
  auto center_x = widget_right_edge/2.f;
  auto right_x = widget_right_edge - left_x;

  auto top_row_y = 25.f;
  auto row_spacing = 18.5f;

  auto row = 0;

  row++;
  install_input<HostagePort>(HostageModule::DURATION_CV, {left_x, top_row_y + row*row_spacing});
  install_switch<HostageSwitch3>(HostageModule::DURATION_SWITCH, {right_x, top_row_y + row*row_spacing}, 2, 1);

  row++;
  install_knob<HostageKnobLarge>(HostageModule::DURATION_KNOB, {center_x, top_row_y + row*row_spacing});

  top_row_y = 82.f;
  row_spacing = 15.f;

  row = 0;
  install_input<HostagePort>(HostageModule::DEFER_IN, {left_x, top_row_y + row*row_spacing});
  install_output<HostagePort>(HostageModule::ACTIVE_OUT, {right_x, top_row_y + row*row_spacing});

  row++;
  install_input<HostagePort>(HostageModule::TRIG_IN, {left_x, top_row_y + row*row_spacing});
  install_output<HostagePort>(HostageModule::EOC_OUT, {right_x, top_row_y + row*row_spacing});

  row++;
  install_input<HostagePort>(HostageModule::STAGE_IN, {left_x, top_row_y + row*row_spacing});
  install_output<HostagePort>(HostageModule::STAGE_OUT, {right_x, top_row_y + row*row_spacing});
}
}
