#include "Transform.h"

dae::Transform::Transform()
	:m_LocalPosition{},
	m_Parent{nullptr}
{}


void dae::Transform::SetLocalPosition(const float x, const float y, const float z)
{
	m_LocalPosition.x = x;
	m_LocalPosition.y = y;
	m_LocalPosition.z = z;
}

glm::vec3 dae::Transform::GetWorldPosition() const
{
	if (m_Parent != nullptr)
		return m_Parent->GetWorldPosition() + GetLocalPosition();
	return GetLocalPosition();
}
