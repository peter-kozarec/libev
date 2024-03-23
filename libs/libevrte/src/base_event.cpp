#include "evrte/base_event.hpp"


evrte::BaseEvent::BaseEvent(const uint8_t type_id) :
    type_id_(type_id)
{
}

evrte::BaseEvent::BaseEvent(const evrte::BaseEvent & other) :
    BaseEvent(other.type_id_)
{
}

evrte::BaseEvent::BaseEvent(evrte::BaseEvent && other) noexcept :
        BaseEvent(other.type_id_)
{
}

evrte::BaseEvent & evrte::BaseEvent::operator=(const evrte::BaseEvent & other)
{
    if (this != &other)
    {
        type_id_ = other.type_id_;
    }
    return *this;
}

evrte::BaseEvent & evrte::BaseEvent::operator=(evrte::BaseEvent && other) noexcept
{
    if (this != &other)
    {
        type_id_ = other.type_id_;
    }
    return *this;
}

uint8_t evrte::BaseEvent::type_id() const
{
    return type_id_;
}
