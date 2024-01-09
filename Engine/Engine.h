#include "Marco.h"
#include "Render/Render.h"
#include "Platform/DXWindow.h"

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

		ComPtr<IDXGISwapChain3> m_swapChain;
		ComPtr<ID3D12Device> m_device;
		ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
		ComPtr<ID3D12CommandAllocator> m_commandAllocator;
		ComPtr<ID3D12CommandQueue> m_commandQueue;
		ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
		ComPtr<ID3D12PipelineState> m_pipelineState;
		ComPtr<ID3D12GraphicsCommandList> m_commandList;
		// TODO: D3D12HelloWindow
	};
}