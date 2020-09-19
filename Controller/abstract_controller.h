#ifndef ABSTRACT_CONTROLLER_H
#define ABSTRACT_CONTROLLER_H

#include "Model/Client/human.h"

class AbstractController {
 public:
  virtual void InitializeMvc() = 0;
  virtual void Tick() = 0;
  virtual void KeyPressed(char) = 0;
  virtual std::pair<
      const std::vector<Human>*, const std::vector<Human>*> GetAllHumans() = 0;
};

#endif //ABSTRACT_CONTROLLER_H
