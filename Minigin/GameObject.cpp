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

void dae::GameObject::SetLocalPosition(const glm::vec3& pos)
{
	//m_Transform.SetLocalPosition(x, y, 0.0f);
	m_LocalPosition = pos;
	SetPositionDirty();
}

const glm::vec3& dae::GameObject::GetLocalPosition()
{
	return m_LocalPosition;
}

void dae::GameObject::SetPositionDirty()
{
	m_PositionIsDirty = true;
	for (auto child : m_pChildren)
		child->SetPositionDirty();
}


const glm::vec3& dae::GameObject::GetWorldPosition()
{
	UpdateWorldPosition();
	return m_WorldPosition;
}

void dae::GameObject::UpdateWorldPosition()
{
	if (m_PositionIsDirty)
	{
		if (!m_pParent)
			m_WorldPosition = m_LocalPosition;
		else
			m_WorldPosition = m_pParent->GetWorldPosition() + m_LocalPosition;
	}
	m_PositionIsDirty = false;
}

void dae::GameObject::RemoveComponent(Component* /*component*/)
{

}

dae::Transform& dae::GameObject::GetTransform()
{
	return m_Transform;
}

void dae::GameObject::SetParent(GameObject* parent, bool keepWorldPosition)
{
	if (IsChild(parent) || parent == this || m_pParent == parent)
		return;

	if (parent == nullptr)
	{
		SetLocalPosition(GetWorldPosition());
	}
	else
	{
		if (keepWorldPosition)
		{
			SetLocalPosition(GetWorldPosition() - parent->GetWorldPosition());
		}
		SetPositionDirty();
	}

	if (m_pParent) m_pParent->RemoveChild(this);
	m_pParent = parent;
	if (m_pParent) { m_pParent->AddChild(this); };
}

dae::GameObject* dae::GameObject::GetParent()
{
	return m_pParent;
}

size_t dae::GameObject::GetChildCount()
{
	return m_pChildren.size();
}

dae::GameObject* dae::GameObject::GetChildAt(unsigned int index)
{
	if (index <= m_pChildren.size())
	{
		return m_pChildren[index];
	}
	return nullptr;
}

bool dae::GameObject::IsChild(GameObject* potentialChild) const
{
	for (const auto* child : m_pChildren)
	{
		if (child == potentialChild)
			return true;

		if (child->IsChild(potentialChild))
			return true;
	}
	return false;
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	if (child == nullptr) return;


	if (std::find(m_pChildren.begin(), m_pChildren.end(), child) == m_pChildren.end()) return;
	//update transform
	m_pChildren.erase(std::remove(m_pChildren.begin(), m_pChildren.end(), child), m_pChildren.end());
	child->m_pParent = nullptr;
}

void dae::GameObject::AddChild(GameObject* child)
{
	if (child == nullptr || child == this) return;

	if (child->m_pParent)
	{
		child->m_pParent->RemoveChild(child);
	};
	child->m_pParent = this;
	if (std::find(m_pChildren.begin(), m_pChildren.end(), child) == m_pChildren.end())
	{
		m_pChildren.emplace_back(child);
	};

}

