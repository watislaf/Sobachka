#ifndef CHEATING_CLIENTS_H
#define CHEATING_CLIENTS_H

#include "clients.h"
#include "Visitor/remove_visitor.h"

class CheatingClients : public Clients {
 public:
  void AddOne() override;
  void Redistribution() override;
  void AcceptVisitor(RemoveVisitor*);
};

#endif //CHEATING_CLIENTS_H
