#include <windows.h>
#include "GamepadInput.h"
#include "InputManager.h"
#include "Xinput.h"

class dae::GamepadInput::XInputPimpl
{
public:
	XInputPimpl(const int gamepadIndex);
	~XInputPimpl();

	bool ProcessGamepadInput();
	bool IsDownThisFrame(unsigned int button) const;
	bool IsUpThisFrame(unsigned int button) const;
	bool IsPressed(unsigned int button) const;
private:
	XINPUT_STATE m_CurrentState{};
	XINPUT_STATE m_PreviouState{};
	WORD m_ButtonPressedThisFrame{};
	WORD m_ButtonReleasedThisFrame{};

	int m_GamepadIndex{};
};

dae::GamepadInput::XInputPimpl::XInputPimpl(const int gamepadIndex)
	: m_GamepadIndex{ gamepadIndex }
{
}

dae::GamepadInput::XInputPimpl::~XInputPimpl()
{
}

bool dae::GamepadInput::XInputPimpl::ProcessGamepadInput()
{
	CopyMemory(&m_PreviouState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(m_GamepadIndex, &m_CurrentState);

	auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ m_PreviouState.Gamepad.wButtons;
	m_ButtonPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
	m_ButtonReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);

	//
	auto binds{ InputManager::GetInstance().GetBinds() };
	for (auto& bind : binds)
	{
		if (bind->state == InputState::Pressed and IsPressed(bind->keyButton))
		{
			bind->command->Execute();
			continue;
		}
		if (bind->state == InputState::Released and IsUpThisFrame(bind->keyButton))
		{
			bind->command->Execute();
			continue;
		}
		if (bind->state == InputState::Held and IsDownThisFrame(bind->keyButton))
		{
			bind->command->Execute();
			continue;
		}
	}

	return true;
}

bool dae::GamepadInput::XInputPimpl::IsDownThisFrame(unsigned int button) const
{
	return m_ButtonPressedThisFrame & button;
}
bool dae::GamepadInput::XInputPimpl::IsUpThisFrame(unsigned int button) const
{
	return m_ButtonReleasedThisFrame & button;
}
bool dae::GamepadInput::XInputPimpl::IsPressed(unsigned int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}

//////
dae::GamepadInput::GamepadInput(const int gamepadIndex)
	:m_Pimpl{ std::make_unique<XInputPimpl>(gamepadIndex) }
{
}

dae::GamepadInput::~GamepadInput()
{
}

bool dae::GamepadInput::ProcessGamepadInput()
{
	return m_Pimpl->ProcessGamepadInput();
}

bool dae::GamepadInput::IsDownThisFrame(unsigned int button) const
{
	return m_Pimpl->IsDownThisFrame(button);
}
bool dae::GamepadInput::IsUpThisFrame(unsigned int button) const
{
	return m_Pimpl->IsUpThisFrame(button);
}

bool dae::GamepadInput::IsPressed(unsigned int button) const
{
	return m_Pimpl->IsPressed(button);
}
