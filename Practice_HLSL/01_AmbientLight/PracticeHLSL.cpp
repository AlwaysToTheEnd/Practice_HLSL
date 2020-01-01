#include "PracticeHLSL.h"

#include "../ATGTK/FindMedia.h"

extern void ExitSample();

using namespace DirectX;
using namespace DirectX::SimpleMath;

using Microsoft::WRL::ComPtr;
using std::make_unique;

PracticeHLSL::PracticeHLSL()
{
	m_DeviceResources = make_unique<DX::DeviceResources>();
	m_DeviceResources->RegisterDeviceNotify(this);
}

PracticeHLSL::~PracticeHLSL()
{
	if (m_DeviceResources)
	{
		m_DeviceResources->WaitForGpu();
	}
}

void PracticeHLSL::Initialize(HWND window, int width, int height)
{
	m_GamePad = make_unique<GamePad>();

	m_Keyboard = make_unique<Keyboard>();

	m_Mouse = make_unique<Mouse>();
	m_Mouse->SetWindow(window);

	m_DeviceResources->SetWindow(window, width, height);

	m_DeviceResources->CreateDeviceResources();
	CreateDeviceDependentResources();
}

void PracticeHLSL::Tick()
{
}

void PracticeHLSL::OnDeviceLost()
{
}

void PracticeHLSL::OnDeviceRestored()
{
}

void PracticeHLSL::OnActivated()
{
}

void PracticeHLSL::OnDeactivated()
{
}

void PracticeHLSL::OnSuspending()
{
}

void PracticeHLSL::OnResuming()
{
}

void PracticeHLSL::OnWindowSizeChanged(int width, int height)
{
}

void PracticeHLSL::NewAudioDevice()
{
}

void PracticeHLSL::GetDefaultSize(int& width, int& height) const
{
}

void PracticeHLSL::Update(DX::StepTimer const& timer)
{
}

void PracticeHLSL::Render()
{
}

void PracticeHLSL::Clear()
{
}

void PracticeHLSL::CreateDeviceDependentResources()
{
	auto device = m_DeviceResources->GetD3DDevice();

	m_GraphicsMemory = make_unique<GraphicsMemory>(device);
	
	m_States = make_unique<CommonStates>(device);

	m_ResourceDescriptors = make_unique<DescriptorHeap>(device,
		D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		Descriptors::Count);
}

void PracticeHLSL::CreateWindowSizeDependentResources()
{
}

void XM_CALLCONV PracticeHLSL::DrawGrid(DirectX::FXMVECTOR xAxis, DirectX::FXMVECTOR yAxis, DirectX::FXMVECTOR origin, size_t xdivs, size_t ydivs, DirectX::GXMVECTOR color)
{
	return void XM_CALLCONV();
}
