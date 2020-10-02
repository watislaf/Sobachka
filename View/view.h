#ifndef VIEW_H
#define VIEW_H

#include <windows.h>
#include <windowsx.h>

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include <ios>
#include <sstream>
#include <string>
#include "Controller/abstract_controller.h"

LRESULT MessagesHandler(HWND window_handle, UINT message_code,
                        WPARAM w_param, LPARAM l_param);

class View {
 public:
  View(AbstractController*);

  void InitializeWindow(HINSTANCE, int);
  int WindowListener();
  void DrawProcess(HDC);

  AbstractController* GetController() const;

 private:
  AbstractController* controller;

};

#endif //VIEW_H
