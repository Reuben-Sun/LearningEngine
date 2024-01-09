#pragma once
#include "Marco.h"
#include "DXWindow.h"

namespace Engine
{
	class Win32Application
	{
	public:
		static int run(DXWindow* pWindow, HINSTANCE hInstance, int nCmdShow);
		static HWND getHwnd() { return m_hwnd; }
	private:
		static HWND m_hwnd;
		static LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}