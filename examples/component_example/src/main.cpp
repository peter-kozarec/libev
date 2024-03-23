#include "ev/event_router.hpp"
#include <iostream>


class ComponentA : public ev::EventHandlerInterface
{
    ev::EventRouter * event_router_;

public:
    explicit ComponentA(ev::EventRouter & event_router)
    {
        event_router_ = &event_router;
        event_router_->add_event_handler(1, *this);
    }

    ~ComponentA() override
    {
        event_router_->remove_event_handler(*this);
    }

    void handle_event(const ev::BaseEvent & event) override
    {
        std::cout << "Hello";
    }
};


int main(int argc, char ** argv)
{
    ev::EventRouter router;

    ComponentA a(router);

    router.post(ev::BaseEvent(1));

    return EXIT_SUCCESS;
}