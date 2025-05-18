#pragma once
#include "Component.h"
#include <memory>

namespace dae
{
	class MoveCommand;
	class DamageCommand;
	class InputComponent : public Component
	{
	public:
		InputComponent(GameObject* gameObject);
		void HandleBinds();
	private:
		void Update(float elapsedSec) override;
		void FixedUpdate(const float fixedTimeStep) override;

		//move
		MoveCommand* GetMoveDownCommand();
		MoveCommand* GetMoveRightCommand();
		MoveCommand* GetMoveLeftCommand();

		//kill

		//push

		//

		MoveCommand* m_pMoveUp;
		MoveCommand* m_pMoveDown;
		MoveCommand* m_pMoveRight;
		MoveCommand* m_pMoveLeft;
		std::unique_ptr<DamageCommand> m_pTakeDamage;
		/*std::unique_ptr<MoveCommand> m_pZ;
		std::unique_ptr<MoveCommand> m_pX;*/
	};
}

