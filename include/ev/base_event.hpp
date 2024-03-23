#ifndef EV_BASE_EVENT_HPP
#define EV_BASE_EVENT_HPP

#include <cstdint>


namespace ev
{
    class BaseEvent
    {
        uint8_t type_id_;

    public:
        BaseEvent() = delete;
        explicit BaseEvent(uint8_t type_id);
        BaseEvent(const BaseEvent & other);
        BaseEvent(BaseEvent && other) noexcept;
        BaseEvent & operator=(const BaseEvent & other);
        BaseEvent & operator=(BaseEvent && other) noexcept;
        virtual ~BaseEvent() = default;

        [[nodiscard]] uint8_t type_id() const;
    };
}

#endif // EV_BASE_EVENT_HPP
