#include <iostream>
#include "clients.h"

void Clients::Tick() {
  for (auto& human : container_) {
    human.Move();
  }
}

void Clients::FreeAll() {
  auto iterator = Begin();
  while (iterator.Get() != nullptr) {
    Human* human = iterator.Get();
    human->SetIsNeedToVisit(false);
    human->SetDestinationPosition({rand() % 800, 1500});
    iterator.Next();
  }
}

const std::vector<Human>* Clients::All() const {
  return &container_;
}

Clients::Iterator::Iterator(std::vector<Human>* container) {
  this->container_ = container;
  while (container->size() >= (uint32_t) iterator_
      and !(*container)[iterator_].IsNeedToVisit()) {
    iterator_++;
  }
}

Human* Clients::Iterator::Get() const {
  if (container_->size() <= (size_t) iterator_)
    return nullptr;
  return &(*container_)[iterator_];
}

void Clients::Iterator::Next() {
  iterator_++;
  while (container_->size() >= (uint32_t) iterator_
      and !(*container_)[iterator_].IsNeedToVisit()) {
    iterator_++;
  }
}

Clients::Iterator Clients::Begin() {
  return Iterator(&container_);
}
