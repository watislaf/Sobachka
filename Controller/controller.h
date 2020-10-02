#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Controller/abstract_controller.h"
#include "View/view.h"
#include "Model/model.h"

class Controller : public AbstractController {
 public:
  void InitializeMvc() override;
  int StartWinApiWindow(HINSTANCE, int);
  void Tick() override;
  void KeyPressed(char) override;
  void FreeAll();

  std::pair<const std::vector<Human>*,
            const std::vector<Human>*> GetAllHumans() override;

 private:
  View* view{};
  Model* model{};
};

#endif //CONTROLLER_H
