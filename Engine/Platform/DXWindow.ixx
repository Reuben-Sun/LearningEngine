// TODO: DXSample
#include "Marco.h"

export module DXWindow;

using namespace Microsoft::WRL;
namespace Engine
{
	export class DXWindow
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

	DXWindow::DXWindow(uint32_t width, uint32_t height, std::wstring name):
		m_width(width), m_height(height), m_title(name)
	{
	}
	DXWindow::~DXWindow()
	{
	}
	void DXWindow::parseCommandLineArgs(WCHAR* argv[], int argc)
	{
		for (int i = 1; i < argc; ++i)
		{
			if (_wcsnicmp(argv[i], L"-warp", wcslen(argv[i])) == 0 ||
				_wcsnicmp(argv[i], L"/warp", wcslen(argv[i])) == 0)
			{
				m_use_warp_device = true;
				m_title = m_title + L" (WARP)";
			}
		}
	}
	void DXWindow::getHardwareAdapter(IDXGIFactory1* pFactory, IDXGIAdapter1** ppAdapter, bool requestHighPerformanceAdapter)
	{
        *ppAdapter = nullptr;

        ComPtr<IDXGIAdapter1> adapter;

        ComPtr<IDXGIFactory6> factory6;
        if (SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6))))
        {
            for (
                UINT adapterIndex = 0;
                SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                    adapterIndex,
                    requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                    IID_PPV_ARGS(&adapter)));
                    ++adapterIndex)
            {
                DXGI_ADAPTER_DESC1 desc;
                adapter->GetDesc1(&desc);

                if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
                {
                    // Don't select the Basic Render Driver adapter.
                    // If you want a software adapter, pass in "/warp" on the command line.
                    continue;
                }

                // Check to see whether the adapter supports Direct3D 12, but don't create the
                // actual device yet.
                if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
                {
                    break;
                }
            }
        }

        if (adapter.Get() == nullptr)
        {
            for (UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex)
            {
                DXGI_ADAPTER_DESC1 desc;
                adapter->GetDesc1(&desc);

                if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
                {
                    // Don't select the Basic Render Driver adapter.
                    // If you want a software adapter, pass in "/warp" on the command line.
                    continue;
                }

                // Check to see whether the adapter supports Direct3D 12, but don't create the
                // actual device yet.
                if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
                {
                    break;
                }
            }
        }

        *ppAdapter = adapter.Detach();
	}
}