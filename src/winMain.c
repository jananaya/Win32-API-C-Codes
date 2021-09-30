#include <Windows.h>

#include "resources/resource.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nFunsterStil)
{
    HWND hwnd;
    MSG message;
    WNDCLASSEX wincl;

    wincl.hInstance = hInstance;
    wincl.lpszClassName = "CLASE_VENTANA";
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);

    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;

    wincl.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

    if (!RegisterClassEx(&wincl))
        return 0;

    hwnd = CreateWindowEx(
        0,
        "CLASE_VENTANA",
        "proyecto Win32 API",
        
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        
        544, 375,
        
        HWND_DESKTOP,
        LoadMenu(hInstance, "Menu"),
        hInstance,
        NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    while (TRUE == GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
}