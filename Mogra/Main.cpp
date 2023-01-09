/// Mogra - Modern Graphics Application

#include "Application.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int cmdShow)
{
    auto app = std::make_unique<Application>(WINDOW_TITLE);

    return 0;
}
