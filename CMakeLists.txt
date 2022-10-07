cmake_minimum_required(VERSION 3.23)
project(stayNormal)

set(CMAKE_CXX_STANDARD 17)

add_executable(stayNormal
        src/core/main.cpp
        src/core/Handler.cpp
        src/core/Game.cpp
        src/core/Ui.cpp
        src/core/World.cpp
        src/primitives/Animation.cpp
        src/utility/tools.cpp
        src/primitives/Entry.cpp
        src/gamestates/Game_State.cpp
        src/objects/Main_Character.cpp
        src/interface/Directions.cpp
        src/interface/Gui.cpp
        src/interface/Corner.cpp
        src/interface/Button.cpp
        src/interface/Panel.cpp src/gamestates/Walk.cpp src/gamestates/Walk.hpp)

#target_compile_options(stayNormal PUBLIC)
target_link_libraries(stayNormal sfml-graphics sfml-window sfml-system)#-static TODO static linkage
