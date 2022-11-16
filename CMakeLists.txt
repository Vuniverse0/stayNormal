cmake_minimum_required(VERSION 3.23)
project(stayNormal)

set(CMAKE_CXX_STANDARD 17)

add_executable(stayNormal
        src/core/main.cpp
        src/core/Handler.cpp
        src/core/Game.cpp
        src/core/Ui.cpp
        src/core/World.cpp

        src/utility/tools.cpp

        src/primitives/Animation.cpp
        src/primitives/Entry.cpp

        src/objects/Main_Character.cpp
        src/objects/Dialogue.cpp
        src/objects/Phrase.cpp
        src/objects/Text.cpp

        src/interface/Directions.cpp
        src/interface/Gui.cpp
        src/interface/Corner.cpp
        src/interface/Button.cpp
        src/interface/Panel.cpp

        src/gamestates/Game_State.cpp
        src/gamestates/Walk_State.cpp
        src/gamestates/Phone_State.cpp
        src/gamestates/GameEvent.cpp
        src/gamestates/Dialogue_State.cpp

        )

#target_compile_options(stayNormal PUBLIC)

target_link_libraries(stayNormal sfml-graphics sfml-window sfml-system)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    #add_definitions(-DBUILD_SHARED_LIBS=OFF  -DSFML_STATIC)
    #target_link_libraries(stayNormal sfml-graphics sfml-window-s-d sfml-system-s-d -static)
ELSE()
    #target_link_libraries(stayNormal sfml-graphics-s sfml-window-s sfml-system-s -static -s)
ENDIF()