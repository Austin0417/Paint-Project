#include "brush.h"
int Brush::GetWidth() { return width_; }
void Brush::SetWidth(int width) { width_ = width; }
void Brush::Start(int x, int y, graphics::Image& image) {
  int radius = GetWidth() / 2;
  // draws a circle with radius half of the width at the desired start location
  image.DrawCircle(x, y, radius, ColorTool::GetColor());
  PathTool::Start(x, y, image);
}
void Brush::MoveTo(int x, int y, graphics::Image& image) {
  int radius = GetWidth() / 2;
  // draws a line from the start to new location with the brush with specified
  // width and color
  image.DrawLine(GetPrevX(), GetPrevY(), x, y, ColorTool::GetColor(),
                 GetWidth());
  // draws a circle at the end of MoveTo to create brush effect
  image.DrawCircle(x, y, radius, ColorTool::GetColor());
  PathTool::MoveTo(x, y, image);
}
graphics::Color Brush::GetColor() { return ColorTool::GetColor(); }
// Your code here to implement the functions in brush.h
