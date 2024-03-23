add_executable(component_example)
target_sources(component_example PRIVATE src/main.cpp)

target_include_directories(component_example PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(component_example PRIVATE ev)