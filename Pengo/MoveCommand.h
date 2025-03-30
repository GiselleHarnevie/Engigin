#pragma once
#include "Command.h"
#include <glm.hpp>

namespace dae
{
	class GameObject;
	class MoveCommand final: public Command
	{
	public:
		MoveCommand(GameObject* gameObject,glm::vec2 direction, float speed);
		void Execute() override;

	private:
		GameObject* m_pGameObject;
		float m_Speed;
		glm::vec2 m_Direction;
	};
}

