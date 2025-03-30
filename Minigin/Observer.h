#pragma once
#include "GameObject.h"

namespace dae
{

	enum class GameEvent 
	{
		OnPlayerDeath,
		OnPlayerDamage
	};

	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void Notify(GameEvent event, GameObject* subject) = 0;
	private:
	};
}

