#include <asset.hpp>
#include <componentlibrary.hpp>

#include "upstage-module.h"
#include "upstage-widget.h"

namespace DHE {

struct UpstageButtonDark : rack::SVGSwitch, rack::MomentarySwitch {
  UpstageButtonDark() {
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/upstage/button-dark-off.svg")));
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/upstage/button-dark-on.svg")));
  }
};

struct UpstageKnobLarge : rack::RoundKnob {
  UpstageKnobLarge() {
    setSVG(rack::SVG::load(rack::assetPlugin(plugin, "res/upstage/knob-large.svg")));
  }
};

struct UpstagePort : rack::SVGPort {
  UpstagePort() {
    background->svg = rack::SVG::load(assetPlugin(plugin, "res/upstage/port.svg"));
    background->wrap();
    box.size = background->box.size;
  }
};

struct UpstageSwitch2 : rack::SVGSwitch, rack::ToggleSwitch {
  UpstageSwitch2() {
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/upstage/switch-2-low.svg")));
    addFrame(rack::SVG::load(rack::assetPlugin(plugin, "res/upstage/switch-2-high.svg")));
  }
};


UpstageWidget::UpstageWidget(rack::Module *module) : ModuleWidget(module, 4, "res/upstage/panel.svg") {
  auto widget_right_edge{width()};

  auto left_x{5.5f};
  auto center_x{widget_right_edge/2.f};
  auto right_x{widget_right_edge - left_x};

  auto top_row_y{25.f};
  auto row_spacing{18.5f};

  auto row{0};
  install_knob<UpstageKnobLarge>(UpstageModule::LEVEL_KNOB, {center_x, top_row_y + row*row_spacing});

  row++;
  install_input<UpstagePort>(UpstageModule::LEVEL_CV_INPUT, {left_x, top_row_y + row*row_spacing});
  install_switch<UpstageSwitch2>(UpstageModule::LEVEL_SWITCH, {right_x, top_row_y + row*row_spacing}, 1, 1);

  row++;
  install_switch<UpstageButtonDark>(UpstageModule::WAIT_BUTTON, {left_x, top_row_y + row*row_spacing});
  install_switch<UpstageButtonDark>(UpstageModule::TRIG_BUTTON, {right_x, top_row_y + row*row_spacing});

  top_row_y = 82.f;
  row_spacing = 15.f;

  row = 0;
  install_input<UpstagePort>(UpstageModule::WAIT_IN, {left_x, top_row_y + row*row_spacing});

  row++;
  install_input<UpstagePort>(UpstageModule::TRIG_IN, {left_x, top_row_y + row*row_spacing});
  install_output<UpstagePort>(UpstageModule::TRIG_OUT, {right_x, top_row_y + row*row_spacing});

  row++;
  install_output<UpstagePort>(UpstageModule::STAGE_OUT, {right_x, top_row_y + row*row_spacing});
}
}