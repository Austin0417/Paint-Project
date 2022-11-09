#ifndef BUTTON_H
#define BUTTON_H
#include "button_listener.h"

class Button {
 public:
  Button(int x, int y, int width, int height, ButtonListener* buttonlistener)
      : x_(x),
        y_(y),
        width_(width),
        height_(height),
        button_listener(buttonlistener) {}
  virtual ~Button() = default;
  int GetX() const;
  int GetY() const;
  int GetWidth() const;
  int GetHeight() const;
  virtual void DoAction() = 0;
  virtual void Draw(graphics::Image& image);
  bool DidHandleEvent(const graphics::MouseEvent& event);

 protected:
  ButtonListener* button_listener;
  // event_handler is a member variable that helps with DidHandleEvent
  bool event_handler;

 private:
  int x_;
  int y_;
  int width_;
  int height_;
};
#endif  // BUTTON_H
// TODO: Define your abstract Button class here.
