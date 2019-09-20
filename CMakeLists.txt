cmake_minimum_required(VERSION 3.12)
project(ECS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wno-unused-parameter -fPIC -march=native")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

find_package(BearLibTerminal REQUIRED)
include_directories(SYSTEM ${BLT_INCLUDE_DIRS})

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} include/game/components/enimy_component.h src/game/systems/game_enemy_system.cpp include/game/system/game_enemy_system.h include/game/components/damage_component.h include/game/components/combat_component.h src/game/systems/combat_control_system.cpp include/game/system/combat_control_system.h include/game/system/enemy_death_system.h src/game/systems/enemy_collision_system.cpp include/game/system/enemy_collision_system.h src/game/systems/death_system.cpp include/game/system/death_system.h src/game/systems/enemy_movement_system.cpp include/game/system/enemy_movement_system.h src/game/systems/endgame_system.cpp include/game/system/endgame_system.h)
include_directories(${PROJECT_HEADERS_DIR})

target_link_libraries(${PROJECT_NAME} ${BLT_LIBRARIES})

file(COPY ${BLT_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add linting before compilation
include(CppLint)
ADD_STYLE_CHECK_TARGET(lint ${PROJECT_NAME} ${PROJECT_HEADERS_DIR} ${PROJECT_SOURCES_DIR})
add_dependencies(${PROJECT_NAME} lint)
