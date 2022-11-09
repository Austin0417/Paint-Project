// TODO: Do not forget to include paint_program.h.
#include "paint_program.h"
#include <iostream>

void PaintProgram::Initialize() {
  brush.SetWidth(20);
  eraser.SetWidth(20);
  // creating unique pointers to toolbuttons and colorbuttons
  std::unique_ptr<ToolButton> pencil_button;
  std::unique_ptr<ToolButton> brush_button;
  std::unique_ptr<ToolButton> bucket_button;
  std::unique_ptr<ToolButton> eraser_button;
  std::unique_ptr<ColorButton> red_button;
  std::unique_ptr<ColorButton> green_button;
  std::unique_ptr<ColorButton> blue_button;
  std::unique_ptr<ColorButton> black_button;
  std::unique_ptr<ColorButton> orange_button;
  // initializing the buttons
  pencil_button =
      std::make_unique<ToolButton>(50, 25, 75, 30, this, ToolType::kPencil);
  brush_button =
      std::make_unique<ToolButton>(150, 25, 75, 30, this, ToolType::kBrush);
  bucket_button =
      std::make_unique<ToolButton>(250, 25, 75, 30, this, ToolType::kBucket);
  eraser_button =
      std::make_unique<ToolButton>(350, 25, 75, 30, this, ToolType::kEraser);
  red_button = std::make_unique<ColorButton>(20, 75, 50, 30, this,
                                             graphics::Color(255, 0, 0));
  green_button = std::make_unique<ColorButton>(120, 75, 50, 30, this,
                                               graphics::Color(0, 255, 0));
  blue_button = std::make_unique<ColorButton>(220, 75, 50, 30, this,
                                              graphics::Color(0, 0, 255));
  black_button = std::make_unique<ColorButton>(320, 75, 50, 30, this,
                                               graphics::Color(0, 0, 0));
  orange_button = std::make_unique<ColorButton>(420, 75, 50, 30, this,
                                                graphics::Color(255, 165, 0));
  // pushes all the unique pointers into the vector member variable
  button_container.push_back(std::move(pencil_button));
  button_container.push_back(std::move(brush_button));
  button_container.push_back(std::move(bucket_button));
  button_container.push_back(std::move(eraser_button));
  button_container.push_back(std::move(red_button));
  button_container.push_back(std::move(green_button));
  button_container.push_back(std::move(blue_button));
  button_container.push_back(std::move(black_button));
  button_container.push_back(std::move(orange_button));
  image_.AddMouseEventListener(*this);
  Redraw();
}
void PaintProgram::Start() { image_.ShowUntilClosed("Scuffed paint program"); }
void PaintProgram::SetActiveColor(const graphics::Color& color,
                                  Button* color_button) {
  // sets the color for all tools
  pencil.SetColor(color);
  brush.SetColor(color);
  bucket.SetColor(color);
  eraser.SetColor(graphics::Color(255, 255, 255));
}
void PaintProgram::SetActiveTool(ToolType tooltype, Button* tool_button) {
  switch (tooltype) {
    // if tooltype = ToolType::kPencil, then active_tool will equal 0, since
    // kPencil has int value of 0 in enum ToolType
    case kPencil:
      active_tool = ToolType::kPencil;
      break;
    // if tooltype = ToolType::kBrush, then active tool will equal 2, since
    // kBrush has int value of 2 in enum ToolType
    case kBrush:
      active_tool = ToolType::kBrush;
      break;
    // if tooltype = ToolType::kBucket, then active tool will equal 1, since
    // kBucket has int value of 1 in enum ToolType
    case kBucket:
      active_tool = ToolType::kBucket;
      break;
    // accounting for the case where tooltype = ToolType::kEraser
    case kEraser:
      active_tool = ToolType::kEraser;
      break;
  }
}
void PaintProgram::OnMouseEvent(const graphics::MouseEvent& event) {
  // checking mouse action
  if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
    // if mouse action is detected, check each button in the vector
    for (int m = 0; m < button_container.size(); m++) {
      // checks each button in vector if they were clicked
      if (button_container[m]->DidHandleEvent(event) == true) {
        // if they were clicked, do the respective action and return
        button_container[m]->DoAction();
        break;
      } else {
        if (active_tool == 0) {
          pencil.Start(event.GetX(), event.GetY(), image_);
          Redraw();
          image_.Flush();
          // 1 is bucket's value in enum, so call bucket's fill function at
          // kPressed x and y
        } else if (active_tool == 1) {
          bucket.Fill(event.GetX(), event.GetY(), image_);
          Redraw();
          image_.Flush();
          // 2 is brush's value in enum, so call brush's start function at
          // kPressed x and y
        } else if (active_tool == 2) {
          brush.Start(event.GetX(), event.GetY(), image_);
          Redraw();
          image_.Flush();
          // 3 is eraser's value in ToolType enum, so call start on eraser
          // object at the location of the click
        } else if (active_tool == 3) {
          eraser.Start(event.GetX(), event.GetY(), image_);
          Redraw();
          image_.Flush();
        }
      }
    }
  }
  // checking mouse action drag
  if (event.GetMouseAction() == graphics::MouseAction::kDragged) {
    if (active_tool == 0) {
      pencil.MoveTo(event.GetX(), event.GetY(), image_);
      Redraw();
      image_.Flush();
      // do nothing for bucket because it only has a fill function, which is
      // called during kPressed
    } else if (active_tool == 1) {
      // calls brush's MoveTo function when kDragged to draw
    } else if (active_tool == 2) {
      brush.MoveTo(event.GetX(), event.GetY(), image_);
      Redraw();
      image_.Flush();
    } else if (active_tool == 3) {
      eraser.MoveTo(event.GetX(), event.GetY(), image_);
      Redraw();
      image_.Flush();
    }
  }
}
std::vector<std::unique_ptr<Button>>* PaintProgram::GetButtonsForTesting() {
  return (&button_container);
}
// small function to help with redrawing buttons
void PaintProgram::Redraw() {
  for (int k = 0; k < button_container.size(); k++) {
    button_container[k]->Draw(image_);
  }
}
