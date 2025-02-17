#pragma once
#include "Component.h"


namespace dae
{
	class Renderer;
	class GameObject;

	class GraphicsComponent :public Component
	{
	public:
		GraphicsComponent(Transform& transform);
		~GraphicsComponent();

		virtual void Update(float elapsedSec) override;
		virtual void Render() const;

	protected:
	};
}

