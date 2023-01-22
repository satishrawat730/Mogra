/// Mogra - Modern Graphics Application

#include "Application.h"

// Linker -> System -> Subsystem = WINDOW  // to enable windowing instead console
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int cmdShow)
int main()
{
   auto app = std::make_unique<Application>(WINDOW_TITLE);

   app->Run();

    return 0;
}

