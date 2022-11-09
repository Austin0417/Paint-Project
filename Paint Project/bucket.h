#include "color_tool.h"
#include "cpputils/graphics/image.h"
#ifndef BUCKET_H
#define BUCKET_H

class Bucket : public ColorTool {
 public:
  void Fill(int, int, graphics::Image& image);
  // implements fill function with recursion
  void RecursiveFill(int, int, graphics::Color start, graphics::Color fill,
                     graphics::Image& image);
  // implements fill function with a queue
  void IterativeFill(int, int, graphics::Color start, graphics::Color fill,
                     graphics::Image& image);

 private:
  graphics::Color color_;
  // Your code here to define the methods in bucket.h
};

#endif  // BUCKET_H
