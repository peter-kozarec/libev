#ifndef EVRTE_BASE_EVENT_HPP
#define EVRTE_BASE_EVENT_HPP

#include <cstdint>


namespace evrte
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

#endif // EVRTE_BASE_EVENT_HPP
