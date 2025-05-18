#pragma once
#include <unordered_map>
#include <memory>

namespace dae
{
	enum class Button : unsigned short
	{
		DPAD_UP = 0x0001,
		DPAD_DOWN = 0x0002,
		DPAD_LEFT = 0x0004,
		DPAD_RIGHT = 0x0008,
		START = 0x0010,
		BACK = 0x0020,
		LEFT_THUMB = 0x0040,
		RIGHT_THUMB = 0x0080,
		LEFT_SHOULDER = 0x0100,
		RIGHT_SHOULDER = 0x0200,
		A = 0x1000,
		B = 0x2000,
		X = 0x4000,
		Y = 0x8000
	};

	class GamepadInput
	{
	public:
		GamepadInput(const int gamepadIndex);
		~GamepadInput();

		bool ProcessGamepadInput();
		bool IsDownThisFrame(unsigned int button) const;
		bool IsUpThisFrame(unsigned int button) const;
		bool IsPressed(unsigned int button) const;
	private:
		class XInputPimpl;
		std::unique_ptr<XInputPimpl> m_Pimpl;
	};

}