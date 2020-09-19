#ifndef HUMAN_H
#define HUMAN_H

#include <windef.h>
#include <wingdi.h>

#include "vector"

enum class Shape {
  ROUND,
  SQUARE
};

class Human {
 public:
  static int GetSpeed();

  Human(std::pair<int, int> position, std::pair<int, int> destination);

  void Draw(HDC hdc) const;
  void Move();

  void SetDestinationPosition(const std::pair<int, int>& destination_position);
  void SetIsNeedToVisit(bool is_need_to_visit);
  void SetShape(Shape shape);

  bool IsNeedToVisit() const;
  bool IsWait() const;

 private:
  static const int SPEED = 9;

  std::pair<int, int> current_position_;
  std::pair<int, int> destination_position_;
  bool is_need_to_visit_ = true;
  Shape shape_;
};

#endif //HUMAN_H
