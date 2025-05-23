#include "InputComponent.h"
#include "InputManager.h"
#include "MoveCommand.h"
#include "DamageCommand.h"

dae::InputComponent::InputComponent(GameObject* gameObject)
	: Component(gameObject)
{

	//move
	m_pMoveUp = InputManager::GetInstance().AddCommand<MoveCommand>(gameObject, glm::vec2{ 0.f,-1.f }, 10.f);
	m_pMoveDown = InputManager::GetInstance().AddCommand<MoveCommand>(gameObject, glm::vec2{ 0.f,1.f }, 10.f);
	m_pMoveLeft = InputManager::GetInstance().AddCommand<MoveCommand>(gameObject, glm::vec2{ -1.f,0.f }, 10.f);
	m_pMoveRight = InputManager::GetInstance().AddCommand<MoveCommand>(gameObject, glm::vec2{ 1.f,0.f }, 10.f);

	//push

	//kill

}

void dae::InputComponent::HandleBinds()
{
	auto& inputInstance = dae::InputManager::GetInstance();
	inputInstance.BindCommand(SDL_SCANCODE_W, dae::InputState::Held, m_pMoveUp);
	inputInstance.BindCommand(SDL_SCANCODE_S, dae::InputState::Held, m_pMoveDown);
	inputInstance.BindCommand(SDL_SCANCODE_A, dae::InputState::Held, m_pMoveLeft);
	inputInstance.BindCommand(SDL_SCANCODE_D, dae::InputState::Held, m_pMoveRight);
	inputInstance.BindCommand(SDL_SCANCODE_C, dae::InputState::Pressed, m_pTakeDamage.get());
}

void dae::InputComponent::Update(float /*elapsedSec*/)
{

}

void dae::InputComponent::FixedUpdate(const float /*fixedTimeStep*/)
{

}

dae::MoveCommand* dae::InputComponent::GetMoveDownCommand()
{
	return m_pMoveDown;
}

