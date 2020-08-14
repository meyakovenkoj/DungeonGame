cmake_minimum_required(VERSION 3.16)
project(DungeonGame)

#include(_FindSFML.cmake)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
#    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
#    -Wsign-conversion
    -Wsign-promo
)
if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()
set(SOURCE
        main.cpp

        core/engine.cpp
        core/map.cpp
        core/menu.cpp

        graphics/sf-entity.cpp
        graphics/sf-item.cpp

        player/creature.cpp
        player/enemy.cpp
        player/game-item.cpp
        player/player.cpp
        player/undead.cpp
        )
add_executable(${PROJECT_NAME} ${SOURCE})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(DungeonGame ${SFML_LIBRARIES})
endif()