
add_library(ev)

target_sources(ev
        PRIVATE
            src/base_event.cpp
            src/event_router.cpp
)

target_include_directories(ev
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        PRIVATE
            include
)
