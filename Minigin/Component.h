#pragma once

#include "Transform.h"

namespace dae
{
	class GameObject;
	enum class ComponentTypes {
		PHYSICS,
		GRAPHICS,
		INPUT,
		FPS
	};

	class Component
	{
	public:
		Component(ComponentTypes type, Transform& transform);
		~Component();

		virtual void FixedUpdate(const float fixedTimeStep);
		virtual void Update(float elapsedSec);

		ComponentTypes GetComponentType();


	protected:
		ComponentTypes m_ComponentType;
		Transform& m_Transform;
	};

}
