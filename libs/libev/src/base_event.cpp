#include "ev/base_event.hpp"


ev::BaseEvent::BaseEvent(const uint8_t type_id) :
    type_id_(type_id)
{
}

ev::BaseEvent::BaseEvent(const ev::BaseEvent & other) :
    BaseEvent(other.type_id_)
{
}

ev::BaseEvent::BaseEvent(ev::BaseEvent && other) noexcept :
        BaseEvent(other.type_id_)
{
}

ev::BaseEvent & ev::BaseEvent::operator=(const ev::BaseEvent & other)
{
    if (this != &other)
    {
        type_id_ = other.type_id_;
    }
    return *this;
}

ev::BaseEvent & ev::BaseEvent::operator=(ev::BaseEvent && other) noexcept
{
    if (this != &other)
    {
        type_id_ = other.type_id_;
    }
    return *this;
}

uint8_t ev::BaseEvent::type_id() const
{
    return type_id_;
}
