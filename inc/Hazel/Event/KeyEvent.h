#pragma once

#include "Hazel/Event/Event.h"


namespace Hazel {

	class keyEvent : public event
	{
	public:
		int getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput)
	protected:
		keyEvent(const int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class keyPressedEvent : public keyEvent
	{
	public:
		keyPressedEvent(const int keycode, const uint16_t repeatCount)
			: keyEvent(keycode), m_RepeatCount(repeatCount) {}

		uint16_t getRepeatCount() const { return m_RepeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(keyPressed)
	private:
		uint16_t m_RepeatCount;
	};

	class keyReleasedEvent : public keyEvent
	{
	public:
		keyReleasedEvent(const int keycode)
			: keyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(keyReleased)
	};

	class keyTypedEvent : public keyEvent
	{
	public:
		keyTypedEvent(const int keycode)
			: keyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(keyTyped)
	};
}