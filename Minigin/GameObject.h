#pragma once
#include <memory>
#include <vector>
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class GameObject final
	{
	public:
		void SetPosition(float x, float y);
		void FixedUpdate(float fixedTimeStep);
		void Update(float elapsedSec);

		void AddComponent(std::shared_ptr<Component> component)
		{
			m_Components.emplace_back(std::move(component));
		}

		template<typename T>
		std::shared_ptr<T> GetComponent(ComponentTypes componentType) 
		{
			for (auto i{ m_Components.begin() }; i != m_Components.end(); ++i)
			{
				std::shared_ptr<Component> component{ *i };
				if (component->GetComponentType() == componentType)
					return std::static_pointer_cast<T>(component);
			}
			return nullptr;
		}

		Transform& GetTransform();

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform{}; 
		std::vector<std::shared_ptr<Component>> m_Components;

	};
}
