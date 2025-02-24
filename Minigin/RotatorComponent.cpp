#include "RotatorComponent.h"
#include "GameObject.h"
#include <iostream>

dae::RotatorComponent::RotatorComponent(GameObject* gameObject, float speed, float radius)
	: Component(gameObject),
	m_RotSpeed{ speed },
	m_Radius{ radius },
	m_Angle{ 0.f },
	m_tempPi{ 3.14f },
	m_oriLocalPos{GetOwner()->GetLocalPosition()}
{
}

void dae::RotatorComponent::Update(float elapsedSec)
{
	  m_Angle += elapsedSec * m_RotSpeed;

    if (m_Angle > m_tempPi * 2)
        m_Angle -= m_tempPi * 2;
    else if (m_Angle < 0)
        m_Angle += m_tempPi * 2;

    glm::vec3 parentPos = GetOwner()->GetLocalPosition();
    glm::vec3 newPos = parentPos + glm::vec3(cos(m_Angle) * m_Radius,
                                             sin(m_Angle) * m_Radius,
                                             0.f);

    GetOwner()->SetLocalPosition(newPos);
    //std::cout << newPos.x << "  " << newPos.y << std::endl;
}

void dae::RotatorComponent::FixedUpdate(const float /*fixedTimeStep*/)
{
}
