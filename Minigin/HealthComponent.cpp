#include "HealthComponent.h"
#include "GameObject.h"
#include "Observable.h"

dae::HealthComponent::HealthComponent(GameObject* gameObject)
	: Component(gameObject)
	, m_pOnHealthChangeEvent(std::make_unique<Observable>())
	, m_pOnPlayerDeathEvent(std::make_unique<Observable>()),
	m_Health{100}
{
}

void dae::HealthComponent::RegisterOnPlayerDeath(Observer* observer)
{
	m_pOnPlayerDeathEvent->AddObserver(observer);
}

void dae::HealthComponent::RegisterOnHealthChange(Observer* observer)
{
	m_pOnHealthChangeEvent->AddObserver(observer);
}

void dae::HealthComponent::TakeDamage(int damage)
{
	m_Health -= damage;
	NotifyHealthChange();

	if (m_Health <= 0)
	{
		NotifyPlayerDeath();
	}
}

void dae::HealthComponent::NotifyHealthChange()
{
	m_pOnHealthChangeEvent->NotifyObservers(dae::GameEvent::OnPlayerDamage, GetOwner());
}

void dae::HealthComponent::NotifyPlayerDeath()
{
	m_pOnPlayerDeathEvent->NotifyObservers(dae::GameEvent::OnPlayerDeath, GetOwner());
}

int dae::HealthComponent::GetHealth() const
{
	return m_Health;
}

void dae::HealthComponent::Update(float /*elapsedSec*/)
{
}

void dae::HealthComponent::FixedUpdate(const float /*fixedTimeStep*/)
{
}
