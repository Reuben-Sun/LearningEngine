#include "Win32Application.h"

namespace Engine
{
	HWND Win32Application::m_hwnd = nullptr;

	int Win32Application::run(DXWindow* pWindow, HINSTANCE hInstance, int nCmdShow)
	{
		int argc;
		LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
		pWindow->parseCommandLineArgs(argv, argc);
		LocalFree(argv);

		WNDCLASSEXW windowClass = { 0 };
		windowClass.cbSize = sizeof(WNDCLASSEXW);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = windowProc;
		windowClass.hInstance = hInstance;
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.lpszClassName = L"DXWindowClass";
		RegisterClassExW(&windowClass);

		RECT windowRect = { 0, 0, static_cast<LONG>(pWindow->getWidth()), static_cast<LONG>(pWindow->getHeight()) };
		AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

		m_hwnd = CreateWindowW(
			windowClass.lpszClassName,
			pWindow->getTitle(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			windowRect.right - windowRect.left,
			windowRect.bottom - windowRect.top,
			nullptr,        // We have no parent window.
			nullptr,        // We aren't using menus.
			hInstance,
			pWindow);

		pWindow->onInit();

		ShowWindow(m_hwnd, nCmdShow);
		MSG msg = {};
		while (msg.message != WM_QUIT)
		{
			// Process any messages in the queue.
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		pWindow->onDestroy();

		return static_cast<char>(msg.wParam);
	}
	LRESULT Win32Application::windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		DXWindow* pWindow = reinterpret_cast<DXWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

		switch (message)
		{
		case WM_CREATE:
		{
			// Save the DXWindow* passed in to CreateWindow.
			LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
		}
		return 0;

		case WM_KEYDOWN:
			if (pWindow)
			{
				//pWindow->OnKeyDown(static_cast<UINT8>(wParam));
			}
			return 0;

		case WM_KEYUP:
			if (pWindow)
			{
				//pWindow->OnKeyUp(static_cast<UINT8>(wParam));
			}
			return 0;

		case WM_PAINT:
			if (pWindow)
			{
				pWindow->onUpdate();
				pWindow->onRender();
			}
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		// Handle any messages the switch statement didn't.
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}
}