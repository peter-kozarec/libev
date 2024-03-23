#ifndef EV_EVENT_HANDLER_INTERFACE_HPP
#define EV_EVENT_HANDLER_INTERFACE_HPP

#include "ev/base_event.hpp"


namespace ev
{
    class EventHandlerInterface
    {
    public:
        virtual ~EventHandlerInterface() = default;

        virtual void handle_event(const BaseEvent & event) = 0;
    };
}

#endif // EV_EVENT_HANDLER_INTERFACE_HPP
