#include "InputManager.h"
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>
#include "KeyboardInput.h"
#include "GamepadInput.h"


bool dae::InputManager::ProcessInput()
{
	SDL_Event e;

	for (auto& gamepad : m_pGamepads)
	{
		gamepad->ProcessGamepadInput();
	}

	bool IsProcessKeyboardInput = m_pKeyboard->ProcessKeyboardInput();

	ImGui_ImplSDL2_ProcessEvent(&e);

	return IsProcessKeyboardInput;
}

void dae::InputManager::BindCommand(unsigned int keyButton, InputState state, Command* command)
{
	std::unique_ptr<Binds> binds = std::make_unique<Binds>();
	binds->keyButton = keyButton;
	binds->state = state;
	binds->command = command;

	m_pBinds.emplace_back(std::move(binds));
}

void dae::InputManager::UnbindCommand(Binds* /*bind*/)
{
	//std::erase(m_pBinds, bind);
}

std::vector<dae::Command*> dae::InputManager::GetCommand() const
{
	std::vector<dae::Command*> newCommandVec;

	for (auto& commands : m_pCommands)
	{
		newCommandVec.emplace_back(commands.get());
	}
	return newCommandVec;
}

std::vector<dae::Binds*> dae::InputManager::GetBinds() const
{
	std::vector<dae::Binds*> newBindsVec;

	for (auto& bind : m_pBinds)
	{
		newBindsVec.emplace_back(bind.get());
	}
	return newBindsVec;
}

void dae::InputManager::AddAllGamepads()
{
	for (int i = 0; i < m_NumOfGamePads; i++)
	{
		std::unique_ptr<GamepadInput> gamepad = std::make_unique<GamepadInput>(i);
		m_pGamepads[i] = std::move(gamepad);
	}
}

dae::InputManager::InputManager()
	: m_pBinds{},
	m_pCommands{}
{
	AddAllGamepads();
}

dae::InputManager::~InputManager()
{

}

void dae::InputManager::RemoveCommand(Command* /*command*/)
{
	//m_pCommands.erase(std::remove(m_pCommands.begin(), m_pCommands.end(), command),m_pCommands.end());
	//std::erase(m_pCommands, command);
}