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

//void dae::GameObject::Render() const
//{
//	const auto& pos = m_transform.GetPosition();
//	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
//}

//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
//}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

dae::Transform& dae::GameObject::GetTransform()
{
	return m_Transform;
}
