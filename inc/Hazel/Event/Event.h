#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "Hazel/Core.h"

namespace Hazel {

	enum class eventType
	{
		none = 0,
		windowClose, windowResize, windowFocus, windowLostFocus, windowMoved,
		appTick, appUpdate, appRender,
		keyPressed, keyReleased, keyTyped,
		mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled
	};

	enum eventCategory
	{
		None = 0,
		eventCategoryApplication    = BIT(0),
		eventCategoryInput          = BIT(1),
		eventCategoryKeyboard       = BIT(2),
		eventCategoryMouse          = BIT(3),
		eventCategoryMouseButton    = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static eventType getStaticType() { return eventType::type; }\
							    virtual eventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class event
	{
        friend class eventDispatcher;
	public:
        event(){}
		virtual ~event() = default;

		virtual eventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		bool isInCategory(eventCategory category)
		{
			return getCategoryFlags() & category;
		}
    private:
        bool m_Handled = false;
	};

	class eventDispatcher
	{
	public:
		eventDispatcher(event& p_Event)
			: m_Event(p_Event)
		{
		}
		
		template<typename T, typename F>
		bool dispatch(const F& func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.m_Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const event& e)
	{
		return os << e.toString();
	}

}
