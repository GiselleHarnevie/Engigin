#include "KeyboardInput.h"
#include "InputManager.h"

dae::KeyboardInput::KeyboardInput()
{
}

bool dae::KeyboardInput::ProcessKeyboardInput()
{
	SDL_Event e;
	auto binds{ InputManager::GetInstance().GetBinds() };
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			return false;
		}
		SDL_Scancode key{ e.key.keysym.scancode };
		for (auto& bind : binds)
		{
			if (static_cast<unsigned int>(key) == bind->keyButton)
			{
				if (bind->state == InputState::Pressed and e.type == SDL_KEYDOWN)
				{
					bind->command->Execute();
					continue;
				}
				if (bind->state == InputState::Released and e.type == SDL_KEYUP)
				{
					bind->command->Execute();
					continue;
				}
			}
		}
	}


	const Uint8* keyboardState{ SDL_GetKeyboardState(nullptr) };
	for (auto& bind : binds)
	{
		if (bind->state == InputState::Held and keyboardState[bind->keyButton])
		{
			bind->command->Execute();
		}
	}

	/*auto& keyHoldCommands{ m_KeyboardCommands[static_cast<unsigned int>(InputState::Held)] };
	for (auto keyholdCommand : keyHoldCommands)
	{
		SDL_Scancode scancode{ keyholdCommand.first };
		if (keyboardState[scancode] && keyholdCommand.second)
			keyholdCommand.second->Execute();

	}*/
	return true;
}
