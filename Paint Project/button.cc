#include "button.h"
#include "color_button.h"
#include "tool_button.h"
int Button::GetX() const { return x_; }
int Button::GetY() const { return y_; }
int Button::GetWidth() const { return width_; }
int Button::GetHeight() const { return height_; }
void Button::Draw(graphics::Image& image) {
  // draws the button
  image.DrawRectangle(GetX(), GetY(), GetWidth(), GetHeight(),
                      graphics::Color(128, 128, 128));
}
bool Button::DidHandleEvent(const graphics::MouseEvent& event) {
  // checking if the mouse action was a click
  if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
    // checking if the click was within bounds of a button
    if (event.GetX() <= GetWidth() + GetX() && event.GetX() >= GetX() &&
        event.GetY() >= GetY() && event.GetY() <= GetY() + GetHeight()) {
      // sets event_handler to true and returns it if within bounds
      event_handler = true;
      return event_handler;
    } else {
      // false otherwise
      event_handler = false;
      return event_handler;
    }
    // checking to see if mouse action was a drag
  } else if (event.GetMouseAction() == graphics::MouseAction::kDragged) {
    // if mouse click was within button boundaries, return true for drag
    if (event_handler == true) {
      return true;
    } else {
      return false;
    }
    // checking for mouse action released
  } else if (event.GetMouseAction() == graphics::MouseAction::kReleased) {
    // checks if the initial click and release were in bounds
    if (event_handler == true && event.GetX() <= GetWidth() + GetX() &&
        event.GetX() >= GetX() && event.GetY() >= GetY() &&
        event.GetY() <= GetY() + GetHeight()) {
      DoAction();
      return event_handler;
    } else {
      return false;
    }
    // if mouse action was not a press, drag, or release, return false
  } else {
    return false;
  }
}

// TODO: Implement the methods in the Button class which are not pure virtual.
