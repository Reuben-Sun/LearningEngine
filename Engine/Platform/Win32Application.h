#pragma once
#include "Marco.h"
#include "DXWindow.h"

namespace Engine
{
	class Application
	{
	public:
		Application(DXWindow* pWindow, HINSTANCE hInstance, int nCmdShow);
		~Application();
		void onUpdate();
		bool needUpdate();
		HWND getHWND() const { return m_hwnd; }
	private:
		DXWindow* m_window{ nullptr };
		HWND m_hwnd;
		MSG msg = {};
		static LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}