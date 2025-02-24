#pragma once
#include "Component.h"


namespace dae
{
	class Renderer;
	class GameObject;

	class GraphicsComponent :public Component
	{
	public:
		GraphicsComponent(GameObject* gameObject);
		~GraphicsComponent() = default;

		virtual void Update(float elapsedSec) override = 0;
		virtual void FixedUpdate(const float fixedTimeStep) override = 0;
		virtual void Render() const = 0;

	protected:

	};
}

