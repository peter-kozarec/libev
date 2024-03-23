#ifndef EVRTE_EVENT_HANDLER_INTERFACE_HPP
#define EVRTE_EVENT_HANDLER_INTERFACE_HPP

#include "evrte/base_event.hpp"


namespace evrte
{
    class EventHandlerInterface
    {
    public:
        virtual ~EventHandlerInterface() = default;

        virtual void handle_event(const BaseEvent & event) = 0;
    };
}

#endif // EVRTE_EVENT_HANDLER_INTERFACE_HPP
