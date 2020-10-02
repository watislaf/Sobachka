#ifndef HONORABLE_CLIENTS_H
#define HONORABLE_CLIENTS_H

#include <Visitor/remove_visitor.h>
#include "clients.h"

class HonorableClients : public Clients {
 public:
  void AddOne() override;
  void Redistribution() override;
  void AcceptVisitor(const RemoveVisitor*);
};

#endif //HONORABLE_CLIENTS_H
