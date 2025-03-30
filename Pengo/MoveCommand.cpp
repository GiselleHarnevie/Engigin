#include "MoveCommand.h"
#include "GameObject.h"

dae::MoveCommand::MoveCommand(GameObject* gameObject, glm::vec2 direction, float speed)
	:m_pGameObject{ gameObject },
	m_Direction{ direction },
	m_Speed{ speed }
{}

void dae::MoveCommand::Execute()
{
	if (m_pGameObject)
	{
		m_pGameObject->SetLocalPosition(
			glm::vec3{ m_pGameObject->GetLocalPosition().x + (m_Direction.x * m_Speed),
			m_pGameObject->GetLocalPosition().y + (m_Direction.y * m_Speed),
			m_pGameObject->GetLocalPosition().z
			});
	}
	
}
