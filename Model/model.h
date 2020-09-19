#ifndef MODEL_H
#define MODEL_H

#include "Controller/abstract_controller.h"
#include "Model/Client/honorable_clients.h"
#include "Model/Client/cheating_clients.h"

class Model {
 public:
  explicit Model(AbstractController*);

  CheatingClients& GetCheatingClients();
  HonorableClients& GetHonorableClients();

 private:
  AbstractController* controller_;

  HonorableClients honorable_clients_;
  CheatingClients cheating_clients_;
};

#endif //MODEL_H
