#pragma once
#include "Observer.h"

//can delete
namespace dae
{
	enum class AchievementType
	{
		FirstBlood
	};

	class Achievement final  :public Observer
	{
	public:
		void Notify(GameEvent event, GameObject* gameObject) override;
		
	private:
		void Unlock(AchievementType achievement);

	};

}
