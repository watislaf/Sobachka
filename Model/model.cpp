#include "model.h"

Model::Model(AbstractController* controller) {
  this->controller_ = controller;
}

  CheatingClients& Model::GetCheatingClients()   {
  return cheating_clients_;
}

  HonorableClients& Model::GetHonorableClients()  {
  return honorable_clients_;
}
