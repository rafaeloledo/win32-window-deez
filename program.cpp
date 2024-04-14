#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hINSTANCE, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	// Register the window class
	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS wc = {};

	wc.lpfWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	// Create the window

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
