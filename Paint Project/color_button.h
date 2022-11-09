#include "button.h"
#ifndef COLOR_BUTTON_H
#define COLOR_BUTTON_H
class ColorButton : public Button {
 public:
  ColorButton(int x, int y, int width, int height,
              ButtonListener* buttonlistener, graphics::Color color)
      : Button(x, y, width, height, buttonlistener), color_(color) {}
  graphics::Color GetColor() const;
  void Draw(graphics::Image& image)
      override;  // draws the button with desired color and dimensions
  void DoAction() override;  // sets the active color to color that was
                             // initialized in constructor
 private:
  graphics::Color color_;
};
#endif  // COLOR_BUTTON_H
