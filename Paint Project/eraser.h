#include "brush.h"
#include "cpputils/graphics/image.h"
#ifndef ERASER_H
#define ERASER_H

class Eraser : public Brush {
 public:
  // returns rgb values of white
  graphics::Color GetColor() override;

 private:
  // color of the eraser
  graphics::Color white = graphics::Color(255, 255, 255);
};

#endif  // ERASER_H
