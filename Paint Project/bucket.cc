#include "bucket.h"

#include <queue>
void Bucket::Fill(int x, int y, graphics::Image& image) {
  IterativeFill(x, y, image.GetColor(x, y), GetColor(), image);
}
void Bucket::RecursiveFill(int x, int y, graphics::Color start,
                           graphics::Color fill, graphics::Image& image) {
  if (image.GetColor(x, y) != start) {
    // base case, do nothing
  } else if (image.GetColor(x, y) == start) {
    // recursive case
    image.SetColor(x, y, GetColor());
    if (x - 1 > 0) {
      RecursiveFill(x - 1, y, start, fill, image);
    }
    if (x + 1 < image.GetWidth()) {
      RecursiveFill(x + 1, y, start, fill, image);
    }
    if (y - 1 > 0) {
      RecursiveFill(x, y - 1, start, fill, image);
    }
    if (y + 1 < image.GetHeight()) {
      RecursiveFill(x, y + 1, start, fill, image);
    }
  }
}
// Point is a class for use with IterativeFill.
class Point {
 public:
  Point(int x, int y) : x_coord(x), y_coord(y) {}
  int GetX();
  int GetY();

 private:
  int x_coord;
  int y_coord;
};
int Point::GetX() { return x_coord; }
int Point::GetY() { return y_coord; }
void Bucket::IterativeFill(int x, int y, graphics::Color start,
                           graphics::Color fill, graphics::Image& image) {
  if (start == fill) {
    return;
  }
  std::queue<Point> points;  // creating queue
  Point first_point(x, y);
  points.push(first_point);
  while (points.size() > 0) {
    Point point = points.front();
    points.pop();
    if (point.GetX() < 0 || point.GetY() < 0 ||
        point.GetX() >= image.GetWidth() || point.GetY() >= image.GetWidth()) {
      continue;
    }
    if (image.GetColor(point.GetX(), point.GetY()) != start) {
      continue;
    }
    image.SetColor(point.GetX(), point.GetY(), fill);
    points.push(Point(point.GetX() - 1, point.GetY()));
    points.push(Point(point.GetX() + 1, point.GetY()));
    points.push(Point(point.GetX(), point.GetY() - 1));
    points.push(Point(point.GetX(), point.GetY() + 1));
  }
}
