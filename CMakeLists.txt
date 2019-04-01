CMAKE_MINIMUM_REQUIRED(VERSION 3.13)
PROJECT(OOP_arcade_2018)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
        lib
        include
)

FILE(GLOB SOURCES_ARCADE
        core/*.cpp
        games/Nibbler/*.cpp
        games/Nibbler/*.hpp
        lib/*.cpp
        include/*.hpp
)

ADD_EXECUTABLE(arcade ${SOURCES_ARCADE})
