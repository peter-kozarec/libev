#include "evrte/event_router.hpp"
#include <iostream>


class ComponentA : public evrte::EventHandlerInterface
{
    evrte::EventRouter * event_router_;

public:
    explicit ComponentA(evrte::EventRouter & event_router)
    {
        event_router_ = &event_router;
        event_router_->add_event_handler(1, *this);
    }

    ~ComponentA() override
    {
        event_router_->remove_event_handler(*this);
    }

    void handle_event(const evrte::BaseEvent & event) override
    {
        std::cout << "Hello";
    }
};


int main(int argc, char ** argv)
{
    evrte::EventRouter router;

    ComponentA a(router);

    router.post(evrte::BaseEvent(1));

    return EXIT_SUCCESS;
}