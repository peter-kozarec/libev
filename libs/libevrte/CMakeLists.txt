
add_library(evrte)

target_sources(evrte
        PRIVATE
            src/base_event.cpp
            src/event_router.cpp
)

target_include_directories(evrte
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        PRIVATE
            include
)
