#pragma once
#include "Singleton.h"
#include <SDL.h>
#include "Command.h"
#include "Gamepad.h"
#include "unordered_map"
#include <array>

namespace dae
{
	enum class InputState
	{
		Pressed = 0,
		Released,
		Held
	};

	class InputManager final : public Singleton<InputManager>
	{
		friend class Singleton;
	public:
		bool ProcessInput();
		//void BindCommand(unsigned int button, InputState state, Command* command);
		void BindCommand(SDL_Scancode key, InputState state, Command* command);

	private:
		InputManager();
		~InputManager();

		static constexpr size_t m_MaxInputStates{ 3 };
		std::vector<int> m_GamepadIndex;
		std::array<std::unordered_map<SDL_Scancode, Command*>, m_MaxInputStates> m_KeyboardCommands;
		//std::unordered_map<unsigned int, std::unordered_map<InputState, Command*>> m_GamepadCommands;
	};

}
