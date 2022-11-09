#include "pencil.h"
void Pencil::Start(int x, int y, graphics::Image& image) {
  image.SetColor(x, y, ColorTool::GetColor());
  PathTool::Start(x, y, image);
  // draws a single pixel with chosen color, x and y start
}
void Pencil::MoveTo(int x, int y, graphics::Image& image) {
  image.DrawLine(GetPrevX(), GetPrevY(), x, y, ColorTool::GetColor(), 1);
  // draws line from start location to new x and y location
  PathTool::MoveTo(x, y, image);
}
// Your code here to implement the functions in pencil.h
// Your code here to implement the functions in pencil.h
