// TODO: DXSample
#pragma once
#include "Marco.h"

using namespace Microsoft::WRL;
namespace Engine
{
	class DXWindow
	{
	public:
		DXWindow(uint32_t width, uint32_t height, std::wstring name);
		virtual ~DXWindow();

		virtual void onInit() = 0;
		virtual void onUpdate() = 0;
		virtual void onRender() = 0;
		virtual void onDestroy() = 0;

		uint32_t getWidth() const { return m_width; }
		uint32_t getHeight() const { return m_height; }
		const WCHAR* getTitle() const { return m_title.c_str(); }
		void parseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);
	protected:
		void getHardwareAdapter(_In_ IDXGIFactory1* pFactory, _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter, bool requestHighPerformanceAdapter = false);
		uint32_t m_width;
		uint32_t m_height;
		bool m_use_warp_device;
	private:
		std::wstring m_title;
	};

	
}