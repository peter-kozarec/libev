
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

# Export targets
install(TARGETS evrte
        EXPORT libevrteTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

# Headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/evrte
        DESTINATION include
)

# Target cmake file
install(EXPORT libevrteTargets
        FILE libevrteTargets.cmake
        DESTINATION lib/cmake/libevrte
)

# Config cmake file
include(CMakePackageConfigHelpers)
configure_package_config_file(
        "${CMAKE_SOURCE_DIR}/Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/libevrteConfig.cmake"
        INSTALL_DESTINATION "lib/cmake/libevrte"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libevrteConfig.cmake"
        DESTINATION "lib/cmake/libevrte"
)

# Config Version cmake file
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/libevrteConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libevrteConfigVersion.cmake"
        DESTINATION "lib/cmake/libevrte"
)
