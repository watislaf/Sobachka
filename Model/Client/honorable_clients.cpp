#include "honorable_clients.h"

void HonorableClients::AddOne() {
  std::pair<int, int> destination{145, 130};
  container_.emplace_back(std::pair<int, int>(400 - rand() % 200, 820),
                          destination);
  container_.back().SetShape(Shape::ROUND);
  Redistribution();
}

void HonorableClients::Redistribution() {
  int k = 0;
  for (auto& human : container_) {
    if (human.IsNeedToVisit()) {
      human.SetDestinationPosition(std::pair<int, int>(
          145, 130 + 22 * k));
      k++;
    }
  }

}

void HonorableClients::AcceptVisitor(const RemoveVisitor* visitor) {
  visitor->VisitHonorable(this);
}
