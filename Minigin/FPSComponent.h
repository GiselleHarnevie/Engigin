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
	private:
	};
}

