#pragma once
#include "Command.h"
#include "GameObject.h"


namespace dae
{
	class GameObjectCommand :public Command
	{
		GameObject* m_actor;
	protected:
		GameObject* GetGameActor() const { return m_actor; }
	public:
		GameObjectCommand(GameObject* actor);
		virtual ~GameObjectCommand();
	};
}

