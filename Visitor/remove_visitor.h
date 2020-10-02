#ifndef REMOVE_VISITOR_H
#define REMOVE_VISITOR_H

#include "Model/Client/clients.h"
#include "Model/Client/human.h"

class RemoveVisitor {
 public:
  static void VisitCheater(Clients*) ;
  static void VisitHonorable(Clients*) ;
};

#endif //REMOVE_VISITOR_H
