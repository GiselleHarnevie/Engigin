#include <SDL.h>
#include "InputManager.h"
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>
#include "Command.h"

bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			auto& keyDownCommands{ m_KeyboardCommands[static_cast<unsigned int>(InputState::Pressed)] };
			SDL_Scancode key{ e.key.keysym.scancode };
			auto it{ keyDownCommands.find(key) };
			if (it != keyDownCommands.end())
				it->second->Execute();
		}
		if (e.type == SDL_KEYUP) {
			auto& keyUpCommands{ m_KeyboardCommands[static_cast<unsigned int>(InputState::Released)] };
			SDL_Scancode key{ e.key.keysym.scancode };
			auto it{ keyUpCommands.find(key) };
			if (it != keyUpCommands.end())
				it->second->Execute();
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		ImGui_ImplSDL2_ProcessEvent(&e);
	}

	const Uint8* keyboardState{ SDL_GetKeyboardState(nullptr) };
	auto& keyHoldCommands{ m_KeyboardCommands[static_cast<unsigned int>(InputState::Held)] };
	for (auto keyholdCommand : keyHoldCommands)
	{
		SDL_Scancode scancode{ keyholdCommand.first };
		if (keyboardState[scancode] && keyholdCommand.second)
			keyholdCommand.second->Execute();

	}

	return true;
}

void dae::InputManager::BindCommand(SDL_Scancode key, InputState state, Command* command)
{
	if (command)
	m_KeyboardCommands[static_cast<unsigned int>(state)][key] = command;
}

dae::InputManager::InputManager()
	: m_KeyboardCommands{}
{
}

dae::InputManager::~InputManager()
{
}


