#pragma once
#include "Singleton.h"
#include <SDL.h>
#include "Command.h"
#include "GamepadInput.h"
#include "KeyboardInput.h"
#include "unordered_map"
#include <array>
#include <memory>

namespace dae
{
	enum class InputState
	{
		Pressed = 0,
		Released,
		Held
	};

	struct Binds
	{
		unsigned int keyButton;
		InputState state;
		Command* command;
	};

	class InputManager final : public Singleton<InputManager>
	{
		friend class Singleton;

	public:
		bool ProcessInput();

		template <typename CommandType, typename ...Args>
		CommandType* AddCommand(Args&&...args);
		void RemoveCommand(Command* command);

		//keyButton meaning button or key
		void BindCommand(unsigned int keyButton, InputState state, Command* command);
		void UnbindCommand(Binds* bind);

		std::vector<Command*> GetCommand() const;
		std::vector<Binds*> GetBinds() const;

		void AddAllGamepads();

	private:
		InputManager();
		~InputManager();

		std::vector<std::unique_ptr<Command>> m_pCommands;
		std::vector<std::unique_ptr<Binds>> m_pBinds;

		static constexpr int m_NumOfGamePads{ 4 };
		std::array<std::unique_ptr<GamepadInput>, m_NumOfGamePads> m_pGamepads;
		std::unique_ptr<KeyboardInput> m_pKeyboard;
	};

	template<typename CommandType, typename ...Args>
	inline CommandType* InputManager::AddCommand(Args&&...args)
	{
		std::unique_ptr<CommandType> command = std::make_unique<CommandType>(std::forward<Args>(args));

		m_pCommands.emplace_back(std::move(command));

		return dynamic_cast<CommandType*>(m_pCommands.back().get());
	}


}
