#pragma once
#include <SDL.h>
#include <unordered_map>


namespace dae
{

	class KeyboardInput
	{
	public:
		KeyboardInput();
		~KeyboardInput() = default; 

		bool ProcessKeyboardInput();
	private:
	};

}