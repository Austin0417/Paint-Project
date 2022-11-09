#ifndef TOOL_BUTTON_H
#define TOOL_BUTTON_H
#include "button.h"
class ToolButton : public Button {
 public:
  ToolButton(int x, int y, int width, int height,
             ButtonListener* buttonlistener, ToolType tooltype)
      : Button(x, y, width, height, buttonlistener), tool_type(tooltype) {}
  ToolType GetToolType() const;
  void Draw(graphics::Image& image) override;
  void DoAction()
      override;  // sets active tool to tool that was initialized in constructor
 private:
  ToolType tool_type;
};
// TODO: Define your ToolButton class here.

#endif  // TOOL_BUTTON_H
