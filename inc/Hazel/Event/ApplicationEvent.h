#pragma once

#include "Hazel/Event/Event.h"

namespace Hazel {

	class windowResizeEvent : public event
	{
	public:
		windowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		unsigned int getWidth() const { return m_Width; }
		unsigned int getHeight() const { return m_Height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(windowResize)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class windowCloseEvent : public event
	{
	public:
		windowCloseEvent() = default;

		EVENT_CLASS_TYPE(windowClose)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appTickEvent : public event
	{
	public:
		appTickEvent() = default;

		EVENT_CLASS_TYPE(appTick)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appUpdateEvent : public event
	{
	public:
		appUpdateEvent() = default;

		EVENT_CLASS_TYPE(appUpdate)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appRenderEvent : public event
	{
	public:
		appRenderEvent() = default;

		EVENT_CLASS_TYPE(appRender)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};
}