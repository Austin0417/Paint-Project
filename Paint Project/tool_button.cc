#include "tool_button.h"
void ToolButton::DoAction() { button_listener->SetActiveTool(tool_type, this); }
void ToolButton::Draw(graphics::Image& image) {
  Button::Draw(image);
  if (tool_type == ToolType::kBrush) {
    // if tool_type equals brush, display text "brush" on button
    image.DrawText(GetX(), GetY(), "brush", 10, graphics::Color(0, 0, 0));
  } else if (tool_type == ToolType::kPencil) {
    // if tool_type equals pencil, display text "pencil" on button
    image.DrawText(GetX(), GetY(), "pencil", 10, graphics::Color(0, 0, 0));
  } else if (tool_type == ToolType::kBucket) {
    // if tool_type equals bucket, display text "bucket" on button
    image.DrawText(GetX(), GetY(), "bucket", 10, graphics::Color(0, 0, 0));
  } else if (tool_type == ToolType::kEraser) {
    image.DrawText(GetX(), GetY(), "eraser", 10, graphics::Color(0, 0, 0));
  }
}
ToolType ToolButton::GetToolType() const { return tool_type; }
// TODO: Implement your ToolButton class methods here.
