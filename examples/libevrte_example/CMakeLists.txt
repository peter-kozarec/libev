add_executable(libevrte_example)
target_sources(libevrte_example PRIVATE src/main.cpp)

target_include_directories(libevrte_example PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(libevrte_example PRIVATE evrte)