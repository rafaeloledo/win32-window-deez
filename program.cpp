#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    // Register the window class
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};

    // long pointer to function
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    // long pointer to string zero terminated
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window

    HWND hwnd = CreateWindowEx(
        0, // optional window styles
        CLASS_NAME, // class
        L"Learn to Program Windows", // text
        WS_OVERLAPPEDWINDOW, // style

        // Size and position
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,

        NULL, // parent
        NULL, // menu
        hInstance, // instance handle
        NULL // additional app data
    );

    if (hwnd == NULL)
        return 0;

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
