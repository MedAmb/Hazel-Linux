#pragma once

#include "Hazel/Event/Event.h"

namespace Hazel {

	class mouseMovedEvent : public event
	{
	public:
		mouseMovedEvent(const float x, const float y)
			: m_MouseX(x), m_MouseY(y) {}

		float getX() const { return m_MouseX; }
		float getY() const { return m_MouseY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseMoved)
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class mouseScrolledEvent : public event
	{
	public:
		mouseScrolledEvent(const float xOffset, const float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		float getXOffset() const { return m_XOffset; }
		float getYOffset() const { return m_YOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseScrolled)
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class mouseButtonEvent : public event
	{
	public:
		int getMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput | eventCategoryMouseButton)
	protected:
		mouseButtonEvent(const int button)
			: m_Button(button) {}

		int m_Button;
	};

	class mouseButtonPressedEvent : public mouseButtonEvent
	{
	public:
		mouseButtonPressedEvent(const int button)
			: mouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseButtonPressed)
	};

	class mouseButtonReleasedEvent : public mouseButtonEvent
	{
	public:
		mouseButtonReleasedEvent(const int button)
			: mouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseButtonReleased)
	};

}