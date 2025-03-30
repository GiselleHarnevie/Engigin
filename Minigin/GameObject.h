#pragma once
#include <memory>
#include <vector>
#include <typeindex>
#include <type_traits>
#include "Transform.h"
#include "Component.h"
#include "Observable.h"


namespace dae
{
	class GameObject final
	{
	public:
		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		virtual void FixedUpdate(float fixedTimeStep);
		virtual void Update(float elapsedSec);

		template<typename ComponentType, typename... Args>
		requires std::is_base_of_v<Component,ComponentType> //add std::derive
		ComponentType& AddComponent(Args&&... args)
		{
			auto component = std::make_unique<ComponentType>(this, std::forward<Args>(args)...);
			ComponentType& ref = *component;
			m_Components.emplace_back(std::move(component));
			return ref;
		}

		template<typename ComponentType>
		ComponentType* GetComponent()
		{
			for (auto i{ m_Components.begin() }; i != m_Components.end(); ++i)
			{
				auto componentType = dynamic_cast<ComponentType*>(i->get());
				if (componentType)
					return componentType;
			}
			return nullptr;
		}
		void RemoveComponent(Component* component);
		
		GameObject* GetParent();
		void SetParent(dae::GameObject* parent, bool keepWorldPosition);
		size_t GetChildCount();
		GameObject* GetChildAt(unsigned int index);
		bool IsChild(GameObject* potentialChild) const;

		Transform& GetTransform();
		const glm::vec3& GetWorldPosition();
		void SetLocalPosition(const glm::vec3& pos);
		const glm::vec3& GetLocalPosition();
		void SetPositionDirty();

	private:
		void UpdateWorldPosition();
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* child);

		Transform m_Transform{};
		glm::vec3 m_WorldPosition{};
		glm::vec3 m_LocalPosition{};
		bool m_PositionIsDirty{};
		std::vector<std::unique_ptr<Component>> m_Components;
		GameObject* m_pParent;
		std::vector<GameObject*> m_pChildren;

		//std::unique_ptr<Observable> m_DiedEvent;
	};
}
