#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"


dae::GameObject::~GameObject() = default;

void dae::GameObject::FixedUpdate(float fixedTimeStep)
{
	for (auto& component : m_Components)
	{
		component->FixedUpdate(fixedTimeStep);
	}
}

void dae::GameObject::Update(float elapsedSec)
{
	for (auto& component : m_Components)
	{
		component->Update(elapsedSec);
	}
		
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

dae::Transform& dae::GameObject::GetTransform()
{
	return m_Transform;
}
