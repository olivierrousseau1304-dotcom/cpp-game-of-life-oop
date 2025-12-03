cmake_minimum_required(VERSION 4.0)
project(JeuDeLaVie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        3.0.2
)


FetchContent_MakeAvailable(sfml)
add_executable(JeuDeLaVie main.cpp
        UI/GUI.cpp
        UI/GUI.h
        UI/Slider.cpp
        UI/Slider.h
)
target_link_libraries(JeuDeLaVie PRIVATE sfml-graphics sfml-window sfml-system)

