#pragma once
#include "Component.h"
#include "TextComponent.h"

namespace dae
{
	class FPSComponent :public Component
	{
	public:
		FPSComponent(Transform& transform, TextComponent& textComponent);
		~FPSComponent();

		void Update(float elapsedSec) override;
		float GetFPS();

	private:
		TextComponent& textComponent;
		int m_FrameCount;
		float m_FPSTimer;
		float m_FPS;
	};
}

