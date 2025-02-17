#include "FPSComponent.h"
#include <iostream>


dae::FPSComponent::FPSComponent(Transform& transform, TextComponent& textComponent)
	: Component(dae::ComponentTypes::FPS, transform),
    m_FrameCount{},
    m_FPSTimer{},
    m_FPS{},
    textComponent{textComponent}
{
}

dae::FPSComponent::~FPSComponent()
{
}

void dae::FPSComponent::Update(float elapsedSec)
{
    m_FPSTimer += elapsedSec;
    m_FrameCount++;
    if (m_FPSTimer >= 1.0f) // Every second
    {
        m_FPS = m_FrameCount / m_FPSTimer;
        //std::cout << "FPS: " << m_FPS << "\n";
        m_FrameCount = 0;
        m_FPSTimer = 0.f;
        textComponent.SetText("FPS: " + std::to_string(m_FPS));
    }
}

float dae::FPSComponent::GetFPS()
{
    return m_FPS;
}
