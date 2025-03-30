#include "Observable.h"
#include "Observer.h"
#include <algorithm>

void dae::Observable::AddObserver(Observer* observer)
{
	if (observer == nullptr) return;

	if (std::find(m_pObservers.begin(), m_pObservers.end(), observer) == m_pObservers.end())
	{
		m_pObservers.emplace_back(observer);
	}
}

void dae::Observable::RemoveObserver(Observer* observer)
{
	if (observer == nullptr) return;

	auto it{ std::find(m_pObservers.begin(), m_pObservers.end(), observer) };
	if (it == m_pObservers.end()) return;
	m_pObservers.erase(it);
}

void dae::Observable::NotifyObservers(GameEvent event, GameObject* /*gameObject*/)
{
	for (auto observer : m_pObservers)
	{
		observer->Notify(event,nullptr);
	}
}
