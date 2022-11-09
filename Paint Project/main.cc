// Don't forget to include headers here!
#include "paint_program.h"
#include "tool_type.h"
int main() {
  // TODO:
  // Create a PaintProgram.
  // Initialize() and Start() the PaintProgram you created.
  PaintProgram paint_program;
  ToolType tool_type = ToolType::kBrush;
  paint_program.SetActiveTool(tool_type, nullptr);
  paint_program.SetActiveColor(graphics::Color(0, 0, 255), nullptr);
  paint_program.Initialize();
  paint_program.Start();
  return 0;
}
