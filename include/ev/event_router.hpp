#ifndef EV_HUB_HPP
#define EV_HUB_HPP

#include "ev/base_event.hpp"
#include "ev/event_handler_interface.hpp"
#include <cstdint>
#include <list>


namespace ev
{
    class EventRouter final
    {
        std::list<EventHandlerInterface *> event_handlers_[ UINT8_MAX ];

    public:
        EventRouter() = default;
        EventRouter(const EventRouter & other) = delete;
        EventRouter(EventRouter && other) noexcept = delete;
        EventRouter & operator=(const EventRouter & other) = delete;
        EventRouter & operator=(EventRouter && other) noexcept = delete;
        ~EventRouter() = default;

        void add_event_handler(uint8_t event_type, EventHandlerInterface & event_handler);
        void remove_event_handler(EventHandlerInterface & event_handler);
        void remove_event_handlers(uint8_t event_type);

        void post(const BaseEvent & event);
    };
}

#endif // EV_HUB_HPP
