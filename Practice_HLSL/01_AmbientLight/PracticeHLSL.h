#pragma once
#include "DeviceResources.h"
#include "StepTimer.h"

class PracticeHLSL : public DX::IDeviceNotify
{
public:
    PracticeHLSL();
    ~PracticeHLSL();

    void Initialize(HWND window, int width, int height);

    void Tick();

    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);
    void NewAudioDevice();

    void GetDefaultSize(int& width, int& height) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void XM_CALLCONV DrawGrid(DirectX::FXMVECTOR xAxis, 
        DirectX::FXMVECTOR yAxis, DirectX::FXMVECTOR origin, 
        size_t xdivs, size_t ydivs, DirectX::GXMVECTOR color);
    
    void Test()
    {
        
    }
private:
    std::unique_ptr<DX::DeviceResources>            m_DeviceResources;
    DX::StepTimer                                   m_Timer;

    std::unique_ptr<DirectX::GamePad>               m_GamePad;
    std::unique_ptr<DirectX::Keyboard>              m_Keyboard;
    std::unique_ptr<DirectX::Mouse>                 m_Mouse;

    DirectX::GamePad::ButtonStateTracker            m_GamePadButtons;
    DirectX::Keyboard::KeyboardStateTracker         m_KeyboardButtons;

    std::unique_ptr<DirectX::GraphicsMemory>                                m_GraphicsMemory;
    std::unique_ptr<DirectX::DescriptorHeap>                                m_ResourceDescriptors;
    std::unique_ptr<DirectX::CommonStates>                                  m_States;
    std::unique_ptr<DirectX::BasicEffect>                                   m_LineEffect;
    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_Batch;
    std::unique_ptr<DirectX::BasicEffect>                                   m_ShapeEffect;
    std::unique_ptr<DirectX::Model>                                         m_Model;
    std::vector<std::shared_ptr<DirectX::IEffect>>                          m_ModelEffects;
    std::unique_ptr<DirectX::EffectTextureFactory>                          m_ModelResources;
    std::unique_ptr<DirectX::GeometricPrimitive>                            m_Shape;
    std::unique_ptr<DirectX::SpriteBatch>                                   m_Sprites;
    std::unique_ptr<DirectX::SpriteFont>                                    m_Font;

    std::unique_ptr<DirectX::AudioEngine>                                   m_AudEngine;
    std::unique_ptr<DirectX::WaveBank>                                      m_WaveBank;
    std::unique_ptr<DirectX::SoundEffect>                                   m_SoundEffect;
    std::unique_ptr<DirectX::SoundEffectInstance>                           m_Effect1;
    std::unique_ptr<DirectX::SoundEffectInstance>                           m_Effect2;

    Microsoft::WRL::ComPtr<ID3D12Resource>                                  m_Texture1;
    Microsoft::WRL::ComPtr<ID3D12Resource>                                  m_Texture2;

    uint32_t                                                                m_AudioEvent;
    float                                                                   m_AudioTimerAcc;

    bool                                                                    m_RetryDefault;

    DirectX::SimpleMath::Matrix                                             m_World;
    DirectX::SimpleMath::Matrix                                             m_View;
    DirectX::SimpleMath::Matrix                                             m_Projection;

    // Descriptors
    enum Descriptors
    {
        WindowsLogo,
        SeaFloor,
        SegoeFont,
        Count = 256
    };
};