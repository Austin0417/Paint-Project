#include "color_tool.h"
#include "cpputils/graphics/image.h"
#include "path_tool.h"
#ifndef BRUSH_H
#define BRUSH_H

class Brush : public ColorTool, public PathTool {
 private:
  int width_;  // width of the brush
  graphics::Color color_;

 public:
  graphics::Color GetColor() override;
  void Start(int, int, graphics::Image& image) override;
  void MoveTo(int, int, graphics::Image& image) override;
  void SetWidth(int);  // sets the width of the brush
  int GetWidth();      // returns the width value of brush
  // Your code here to define the methods in brush.h
};

#endif  // BRUSH_H
