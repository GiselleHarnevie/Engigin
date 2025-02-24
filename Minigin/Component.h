#pragma once

#include "Transform.h"

namespace dae
{
	class GameObject;

	class Component
	{
		GameObject* m_pOwner;
	public:
		virtual ~Component()= default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator= (const Component& other) = delete;
		Component& operator= (Component&& other) = delete;

		virtual void Update(float elapsedSec) =0;
		virtual void FixedUpdate(const float fixedTimeStep)=0;

	protected:
		explicit Component(GameObject* pOwner);
		GameObject* GetOwner() const;
	};

}
