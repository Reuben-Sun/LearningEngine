#include "Marco.h"
#include "Render/Render.h"
#include "Platform/DXWindow.h"
#include "Platform/Win32Application.h"

using Microsoft::WRL::ComPtr;

namespace Engine
{
	class Engine: public DXWindow
	{
	public:
		Engine(uint32_t width, uint32_t height, std::wstring name);
		void onInit() override;
		void onUpdate() override;
		void onRender() override;
		void onDestroy() override;
	private:
		static const uint32_t FrameCount = 2;

		ComPtr<IDXGISwapChain3> m_swap_chain;
		ComPtr<ID3D12Device> m_device;
		ComPtr<ID3D12Resource> m_render_targets[FrameCount];
		ComPtr<ID3D12CommandAllocator> m_command_allocator;
		ComPtr<ID3D12CommandQueue> m_command_queue;
		ComPtr<ID3D12DescriptorHeap> m_rtv_heap;
		ComPtr<ID3D12PipelineState> m_pipeline_state;
		ComPtr<ID3D12GraphicsCommandList> m_command_list;
		// TODO: D3D12HelloWindow
	};
}