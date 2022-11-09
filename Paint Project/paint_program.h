#include <memory>
#include <vector>
#include "brush.h"
#include "bucket.h"
#include "button.h"
#include "button_listener.h"
#include "clear.h"
#include "color_button.h"
#include "cpputils/graphics/image.h"
#include "eraser.h"
#include "pencil.h"
#include "tool_button.h"
#include "tool_type.h"

#ifndef PAINT_PROGRAM_H
#define PAINT_PROGRAM_H

/*enum ToolType {
  kPencil = 0,
  kBucket,
  kBrush,
};*/
class PaintProgram : public graphics::MouseEventListener,
                     public ButtonListener {
 public:
  // initializes image_ to be 500x500
  PaintProgram() : image_(graphics::Image(500, 500)) {}
  void Initialize();
  void Start();
  void SetActiveTool(ToolType, Button* tool_button) override;
  void SetActiveColor(const graphics::Color& color,
                      Button* color_listener) override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;
  graphics::Image* GetImageForTesting() { return &image_; }
  std::vector<std::unique_ptr<Button>>* GetButtonsForTesting();
  void Redraw();  // redraws all buttons in vector

 private:
  // The image_ which will be the canvas for the PaintProgram.
  graphics::Image image_;
  Brush brush;
  Pencil pencil;
  Bucket bucket;
  Eraser eraser;
  int active_tool;  // tracks the integer value of ToolType enum
  std::vector<std::unique_ptr<Button>> button_container;
};

#endif  // PAINT_PROGRAM_H
