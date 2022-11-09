#include "path_tool.h"
void PathTool::Start(int x, int y, graphics::Image& image) {
  last_x = x;
  last_y = y;
}
void PathTool::MoveTo(int x, int y, graphics::Image& image) {
  last_x = x;
  last_y = y;
}
int PathTool::GetPrevX() { return last_x; }
int PathTool::GetPrevY() { return last_y; }
// Your code here to implement methods defined in path_tool.h.

// Your code here to implement methods defined in path_tool.h.
