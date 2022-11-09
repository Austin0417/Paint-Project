#ifndef CLEAR_H
#define CLEAR_H
#include "button.h"
#include "tool_button.h"

class ClearButton : public ToolButton {
 public:
 ClearButton(int x, int y, int width, int height, ButtonListener* buttonlistener, ToolType tooltype) : ToolButton(x, y, width, height, buttonlistener, tooltype) {}
  void DoAction() override;
  graphics::Image GetImage();
 private:
  graphics::Image image_;
};
#endif 
