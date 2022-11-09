#include "clear.h"
void ClearButton::DoAction() {
  GetImage().DrawRectangle(0, 0, 500, 500, graphics::Color(255, 255, 255));
}
graphics::Image ClearButton::GetImage() { return image_; }
