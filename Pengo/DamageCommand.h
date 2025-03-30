#pragma once
#include "Command.h"

namespace dae
{
	class GameObject;
	class HealthComponent;
	class DamageCommand : public Command
	{
	public:
		DamageCommand(GameObject* gameObject, int damage);
		void Execute() override;
	private:
		GameObject* m_pGameObject;
		HealthComponent* healthComponent;
		int m_Damage;
	};
}

