#include "color_tool.h"
#include "cpputils/graphics/image.h"
#include "path_tool.h"
#ifndef PENCIL_H
#define PENCIL_H

class Pencil : public PathTool, public ColorTool {
 public:
  void MoveTo(
      int, int,
      graphics::Image& image) override;  // drags pencil to desired location
  void Start(
      int, int,
      graphics::Image& image) override;  // starts pencil at desired location

 private:
  graphics::Color color_;
};

#endif  // PENCIL_H
