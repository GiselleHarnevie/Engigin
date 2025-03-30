#pragma once
#include "Observer.h"
#include "GameObject.h"
#include <vector>

namespace dae
{
	class Observer;
	enum class GameEvent;
	class Observable //subject class
	{
	public:
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);
		void NotifyObservers(GameEvent event, GameObject* gameObject);
	protected:
	private:
		std::vector<Observer*> m_pObservers;
	};
}