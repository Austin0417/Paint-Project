#include "cpputils/graphics/image.h"

#ifndef COLOR_TOOL_H
#define COLOR_TOOL_H

class ColorTool {
 public:
  // sets the color for all tools
  void SetColor(const graphics::Color& color);
  // gets the color for all tools
  virtual graphics::Color GetColor();

 private:
  graphics::Color color_;
  // Your code here to define the methods in color_tool.h
};

#endif  // COLOR_TOOL_H
