#include "evrte/event_router.hpp"


void evrte::EventRouter::add_event_handler(uint8_t event_type, EventHandlerInterface & event_handler)
{
    event_handlers_[event_type].push_back(&event_handler);
}

void evrte::EventRouter::remove_event_handler(EventHandlerInterface & event_handler)
{
    for (auto & i : event_handlers_)
    {
        i.remove(&event_handler);
    }
}

void evrte::EventRouter::remove_event_handlers(uint8_t event_type)
{
    event_handlers_[event_type].clear();
}

void evrte::EventRouter::post(const evrte::BaseEvent & event)
{
    for (auto & event_handler : event_handlers_[event.type_id()])
    {
        event_handler->handle_event(event);
    }
}
