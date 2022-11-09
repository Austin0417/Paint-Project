#include "color_button.h"
void ColorButton::DoAction() {
  button_listener->SetActiveColor(GetColor(), this);
}
void ColorButton::Draw(graphics::Image& image) {
  Button::Draw(image);
  image.DrawRectangle(GetX(), GetY(), GetWidth(), GetHeight(), GetColor());
}
graphics::Color ColorButton::GetColor() const { return color_; }
