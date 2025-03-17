cmake_minimum_required(VERSION 3.10)

project(sim)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_subdirectory(dynamics)
add_subdirectory(math)
add_subdirectory(gui)
add_subdirectory(cli)
add_subdirectory(test)

add_executable(sim_cli ${CMAKE_SOURCE_DIR}/cli/cli.c)
add_executable(sim_gui ${CMAKE_SOURCE_DIR}/gui/gui.c)

# target_link_libraries(cli dynamics test cli) target_link_libraries(gui
# dynamics test gui)
