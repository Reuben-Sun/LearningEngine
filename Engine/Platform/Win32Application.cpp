#include "Win32Application.h"

namespace Engine
{
	Application::Application(DXWindow* pWindow, HINSTANCE hInstance, int nCmdShow)
		: m_window(pWindow)
	{
		int argc;
		LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
		m_window->parseCommandLineArgs(argv, argc);
		LocalFree(argv);

		WNDCLASSEXW windowClass = { 0 };
		windowClass.cbSize = sizeof(WNDCLASSEXW);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = windowProc;
		windowClass.hInstance = hInstance;
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.lpszClassName = L"DXWindowClass";
		RegisterClassExW(&windowClass);

		RECT windowRect = { 0, 0, static_cast<LONG>(m_window->getWidth()), static_cast<LONG>(m_window->getHeight()) };
		AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

		m_hwnd = CreateWindowW(
			windowClass.lpszClassName,
			m_window->getTitle(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			windowRect.right - windowRect.left,
			windowRect.bottom - windowRect.top,
			nullptr,        // We have no parent window.
			nullptr,        // We aren't using menus.
			hInstance,
			m_window);

		m_window->onInit();

		ShowWindow(m_hwnd, nCmdShow);
	}
	Application::~Application()
	{
		m_window->onDestroy();
	}
	void Application::onUpdate()
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	bool Application::needUpdate()
	{
		return msg.message != WM_QUIT;
	}
	LRESULT Application::windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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