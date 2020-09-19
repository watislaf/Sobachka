#ifndef CLIENTS_H
#define CLIENTS_H

#include "string"
#include "vector"
#include "human.h"
#include "cmath"

class Clients {
 public:
  virtual void AddOne() = 0;
  virtual void Redistribution() = 0;

  void Tick();
  void FreeAll();
  const std::vector<Human>* All() const;

  class Iterator {
   public:
    friend Clients;
    Human* Get() const;
    void Next();

   private:
    explicit Iterator(std::vector<Human>* container);
    int iterator_ = 0;
    std::vector<Human>* container_;
  };

  Iterator Begin();

 protected:
  std::vector<Human> container_;

};

#endif //CLIENTS_H
