#include "Controller/controller.h"

//Interfaces id
#define WinApi 123321

// View id
#define ViewInterface WinApi

// WinApi view
#if  ViewInterface == WinApi

INT WinMain(HINSTANCE instance_handle_arg, HINSTANCE, LPSTR, int n_cmd_show) {
  Controller controller = Controller();
  controller.InitializeMvc();

  return controller.StartWinApiWindow(instance_handle_arg, n_cmd_show);
}

#endif //WinApi