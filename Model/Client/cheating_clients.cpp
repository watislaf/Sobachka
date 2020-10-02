#include "cheating_clients.h"

void CheatingClients::AddOne() {
  container_.emplace_back(
      std::pair<int, int>(1400, 800 - std::rand() % 820),
      std::pair<int, int>(145, 130)
  );
  container_.back().SetShape(Shape::SQUARE);
  Redistribution();
}

void CheatingClients::Redistribution() {
  for (auto& human : container_) {
    if (human.IsNeedToVisit()) {
      human.SetDestinationPosition(std::pair<int, int>(
          200 - std::rand() % 100 + 80,
          130 - std::rand() % 100 + 100));
    }
  }
}

void CheatingClients::AcceptVisitor(RemoveVisitor* visitor) {
  visitor->VisitCheater(this);
}

