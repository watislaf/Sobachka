#include "controller.h"

void Controller::InitializeMvc() {
  model = new Model(this);
  view = new View(this);
}

int Controller::StartWinApiWindow(HINSTANCE instance_handle_arg,
                                  int n_cmd_show) {
  view->InitializeWindow(instance_handle_arg, n_cmd_show);
  return view->WindowListener();
}

void Controller::Tick() {
  model->GetHonorableClients().Tick();
  model->GetCheatingClients().Tick();
}

void Controller::KeyPressed(char x) {
  RemoveVisitor visitor;

  switch (x) {
    case 'R':FreeAll();
      break;
    case 'A':model->GetCheatingClients().AddOne();
      break;
    case 'D':model->GetHonorableClients().AddOne();
      break;
    case 'E':model->GetHonorableClients().AcceptVisitor(&visitor);
      break;
    case 'Q':model->GetCheatingClients().AcceptVisitor(&visitor);
      break;
  }
}

void Controller::FreeAll() {
  model->GetCheatingClients().FreeAll();
  model->GetHonorableClients().FreeAll();
}

std::pair<const std::vector<Human>*,
          const std::vector<Human>*> Controller::GetAllHumans() {
  return {model->GetHonorableClients().All(),
          model->GetCheatingClients().All()};
}

