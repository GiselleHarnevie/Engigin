#pragma once
#include "Component.h"
#include <memory>

namespace dae
{
	class Observer;
	class Observable;
	class HealthComponent : public Component
	{
	public:
		HealthComponent(GameObject* gameObject);
		~HealthComponent() =default;

		void RegisterOnPlayerDeath(Observer* observer);
		void RegisterOnHealthChange(Observer* observer);
		void TakeDamage(int damage);
		void NotifyHealthChange();
		void NotifyPlayerDeath();
		int GetHealth() const;
	private:
		std::unique_ptr<Observable> m_pOnHealthChangeEvent;
		std::unique_ptr<Observable> m_pOnPlayerDeathEvent;
		int m_Health;

		void Update(float elapsedSec) override;
		void FixedUpdate(const float fixedTimeStep) override;
	};
}

