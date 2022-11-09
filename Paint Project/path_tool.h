#include "cpputils/graphics/image.h"

#ifndef PATH_TOOL_H
#define PATH_TOOL_H

class PathTool {
 public:
  // starts the brush and pencil tool at x and y
  virtual void Start(int x, int y, graphics::Image& image);
  // moves the brush and pencil to x and y
  virtual void MoveTo(int x, int y, graphics::Image& image);

 protected:
  int GetPrevX();
  int GetPrevY();

 private:
  int last_x;
  int last_y;
  // Your code here to define the methods in path_tool.h
};

#endif  // PATH_TOOL_H
