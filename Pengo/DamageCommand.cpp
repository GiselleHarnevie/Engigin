#include "DamageCommand.h"
#include "GameObject.h"
#include "HealthComponent.h"

dae::DamageCommand::DamageCommand(GameObject* gameObject, int damage)
	:m_pGameObject{gameObject}
	,healthComponent{ m_pGameObject->GetComponent<dae::HealthComponent>() }
	,m_Damage{damage}
{
}

void dae::DamageCommand::Execute()
{
	if (healthComponent)
	{
		healthComponent->TakeDamage(m_Damage);
	}
}
