#include "remove_visitor.h"

void RemoveVisitor::VisitCheater(Clients* client) {
  int waiting = 0;
  auto iterator = client->Begin();
  while (iterator.Get() != nullptr) {
    waiting++;
    iterator.Next();
  }
  if (waiting == 0) {
    return;
  }

  int random_human = rand() % (waiting);

  iterator = client->Begin();
  while (random_human) {
    iterator.Next();
    random_human--;
  }
  Human* human = iterator.Get();
  human->SetIsNeedToVisit(false);
  human->SetDestinationPosition({2000, 150});

  client->Redistribution();
}

void RemoveVisitor::VisitHonorable(Clients* client) {
  auto iterator = client->Begin();
  if (iterator.Get() != nullptr) {
    Human* human = iterator.Get();
    human->SetIsNeedToVisit(false);
    human->SetDestinationPosition({-2000, 150});
  }
  client->Redistribution();
}
