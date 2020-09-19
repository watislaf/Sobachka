#include <cmath>
#include "human.h"
const int Human::SPEED;

int Human::GetSpeed() {
  return SPEED;
}

Human::Human(std::pair<int, int> position, std::pair<int, int> destination)
    : current_position_(std::move(position)),
      destination_position_(std::move(destination)) {}

void Human::Draw(HDC hdc) const {
  if (current_position_.first > 1720 and current_position_.second > 980)
    return;

  static HPEN blue_pen_handle;
  if (!is_need_to_visit_) {
    blue_pen_handle = CreatePen(PS_ENDCAP_ROUND, 1, RGB(0, 0, 255));
  } else {
    blue_pen_handle = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
  }
  SelectObject(hdc, blue_pen_handle);

  if (shape_ == Shape::SQUARE) {
    Rectangle(hdc,
              current_position_.first - 10,
              current_position_.second - 10,
              current_position_.first + 10,
              current_position_.second + 10 - rand() % 4 + 2);
  }
  if (shape_ == Shape::ROUND) {
    Ellipse(hdc,
            current_position_.first - 10 - (rand() % 4 * !IsWait()),
            current_position_.second - 10,
            current_position_.first + 10 - (rand() % 4 * !IsWait()),
            current_position_.second + 10);
  }
  DeleteObject(blue_pen_handle);
}

void Human::Move() {
  if (std::abs(current_position_.first - destination_position_.first)
      >= Human::SPEED) {
    current_position_.first -= Human::SPEED *
        (current_position_.first - destination_position_.first) /
        std::abs(current_position_.first - destination_position_.first);
  }

  if (std::abs(current_position_.second - destination_position_.second)
      >= Human::SPEED) {
    current_position_.second -= Human::SPEED *
        (current_position_.second - destination_position_.second) /
        std::abs(current_position_.second - destination_position_.second);
  }
}

void Human::SetDestinationPosition(
    const std::pair<int, int>& destination_position) {
  Human::destination_position_ = destination_position;
}

void Human::SetIsNeedToVisit(bool is_need_to_visit) {
  is_need_to_visit_ = is_need_to_visit;
}
void Human::SetShape(Shape shape) {
  Human::shape_ = shape;
}

bool Human::IsNeedToVisit() const {
  return is_need_to_visit_;
}

bool Human::IsWait() const {
  int speed = Human::GetSpeed();

  bool is_finish_by_x =
      std::abs(current_position_.first - destination_position_.first) <= speed;
  bool is_finish_by_y =
      std::abs(current_position_.second - destination_position_.second) <= speed;
  return is_finish_by_x and is_finish_by_y;
}
