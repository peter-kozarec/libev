[![C++ Build](https://github.com/peter-kozarec/libevrte/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/peter-kozarec/libevrte/actions/workflows/cmake-single-platform.yml)
# libevrte: C++ Library for event routing and handling

## Prerequisites

Before building and using the evrte library, make sure you have the following dependencies installed:

- CMake (version 3.15 or higher)

## Building

Follow these steps to build the libio library:

1. Clone the repository:

   ```bash
   git clone https://github.com/peter-kozarec/libevrte.git
   ```

2. Create a build directory and navigate into it:

   ```bash
   cd libevrte
   mkdir build
   cd build
   ```

3. Generate build files with CMake:

   ```bash
   cmake ..
   ```

4. Build the library:

   ```bash
   cmake --build .
   ```

## Usage

To use the libevrte library in your C++ project, using cmake:

   ```cmake
cmake_minimum_required(VERSION 3.15)
project(libevrte_test)

set(CMAKE_CXX_STANDARD 20)

find_package(libevrte REQUIRED)

add_executable(libevrte_test main.cpp)

target_link_libraries(libevrte_test PRIVATE ${LIBEVRTE_LIBRARIES})
target_compile_options(libevrte_test PRIVATE "-fcoroutines")
   ```

## Example

Here's a simple example:

```cpp
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
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
