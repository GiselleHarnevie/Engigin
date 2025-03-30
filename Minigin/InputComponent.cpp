#include "InputComponent.h"
#include "InputManager.h"
#include "MoveCommand.h"
#include "DamageCommand.h"

dae::InputComponent::InputComponent(GameObject* gameObject)
	: Component(gameObject)
	, m_pMoveUp{ std::make_unique<dae::MoveCommand>(gameObject, glm::vec2{0.f,-1.f}, 10.f) }
	, m_pMoveDown{ std::make_unique<dae::MoveCommand>(gameObject, glm::vec2{0.f,1.f}, 10.f) }
	, m_pMoveLeft{ std::make_unique<dae::MoveCommand>(gameObject, glm::vec2{-1.f,0.f}, 10.f) }
	, m_pMoveRight{ std::make_unique<dae::MoveCommand>(gameObject, glm::vec2{1.f,0.f}, 10.f) }
	, m_pTakeDamage{std::make_unique<dae::DamageCommand>(gameObject,20)}
{

}

void dae::InputComponent::HandleBinds()
{
	auto& inputInstance = dae::InputManager::GetInstance();
	inputInstance.BindCommand(SDL_SCANCODE_W, dae::InputState::Held, m_pMoveUp.get());
	inputInstance.BindCommand(SDL_SCANCODE_S, dae::InputState::Held, m_pMoveDown.get());
	inputInstance.BindCommand(SDL_SCANCODE_A, dae::InputState::Held, m_pMoveLeft.get());
	inputInstance.BindCommand(SDL_SCANCODE_D, dae::InputState::Held, m_pMoveRight.get());
	inputInstance.BindCommand(SDL_SCANCODE_C, dae::InputState::Pressed, m_pTakeDamage.get());
}

void dae::InputComponent::Update(float /*elapsedSec*/)
{
}

void dae::InputComponent::FixedUpdate(const float /*fixedTimeStep*/)
{
}
