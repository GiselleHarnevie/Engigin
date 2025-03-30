#include "Achievement.h"
#include "Observable.h"
#include <iostream>


void dae::Achievement::Notify(GameEvent event, GameObject* /*gameObject*/)
{
	switch (event)
	{
	case dae::GameEvent::OnPlayerDeath:
		Unlock(AchievementType::FirstBlood);
		break;
	case dae::GameEvent::OnPlayerDamage:
		break;
	default:
		break;
	}
}

void dae::Achievement::Unlock(AchievementType achievement)
{
	std::cout << "Achievement" << static_cast<int>(achievement)<< std::endl;
}
