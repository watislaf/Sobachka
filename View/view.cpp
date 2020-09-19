#include "view.h"

View* global_view;

View::View(AbstractController* controller) {
  this->controller = controller;
  global_view = this;
}

void View::InitializeWindow(HINSTANCE instance_handle_arg, int n_cmd_show) {
  HINSTANCE instance_handle = instance_handle_arg;

  const char kClassName[] = "msg_server_class";
  WNDCLASS window_class = {};
  window_class.lpfnWndProc = MessagesHandler;
  window_class.hInstance = instance_handle;
  window_class.lpszClassName = kClassName;
  window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
  window_class.hbrBackground = GetStockBrush(WHITE_BRUSH);
  RegisterClass(&window_class);

  HWND handle_of_window = CreateWindowEx(0, kClassName, "WinAPI Example",
                                         WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                                         CW_USEDEFAULT, 500, 500, nullptr,
                                         nullptr, instance_handle, nullptr);

  ShowWindow(handle_of_window, n_cmd_show);
}

int View::WindowListener() {
  MSG message = {};

  while (GetMessage(&message, nullptr, 0, 0)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }

  return (int) message.wParam;
}

LRESULT MessagesHandler(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param) {
  switch (message_code) {
    case WM_CREATE: {
      SetTimer(window_handle, 1, 50, NULL);
      break;
    }
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(window_handle, &ps);
      global_view->DrawProcess(hdc);
      EndPaint(window_handle, &ps);
      break;
    }
    case WM_TIMER: {
      global_view->GetController()->Tick();
      InvalidateRect(window_handle, nullptr, true);
      break;
    }
    case WM_KEYDOWN: {
      global_view->GetController()->KeyPressed(w_param);
      break;
    }
    case WM_DESTROY: {
      PostQuitMessage(0);
      break;
    }
    default: {
      return DefWindowProc(window_handle, message_code, w_param, l_param);
    }
  }
  return 0;
}

void View::DrawProcess(HDC hdc) {
  // Shop
  Rectangle(hdc, 320, 120, 120, 20);

  //Clients
  std::pair<const std::vector<Human>*, const std::vector<Human>*> containers =
      controller->GetAllHumans();

  for (const auto& human : *containers.second) {
    human.Draw(hdc);
  }
  for (const auto& human : *containers.first) {
    human.Draw(hdc);
  }
}

AbstractController* View::GetController() const {
  return controller;
}


