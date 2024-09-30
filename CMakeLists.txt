cmake_minimum_required(VERSION 3.28.1)
project(blackboard CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories("src")
include_directories("include")

add_executable(blackboard
    src/main.cpp
    include/IFigure.h
    include/BoardMemento.h
    include/BoardCaretaker.h
    src/Memento/BoardCaretaker.cpp
    src/Memento/BoardMemento.cpp
    include/Board.h
    src/Memento/Board.cpp
    include/FileProcessor.h
    src/Processors/FileProcessor.cpp
    src/Figures/Rectangle.h
    src/Figures/Rectangle.cpp
    src/Figures/Triangle.h
    src/Figures/Triangle.cpp
    src/Figures/Circle.cpp)