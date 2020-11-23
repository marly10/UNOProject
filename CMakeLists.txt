cmake_minimum_required(VERSION 3.17)
project(lab12_UnoAi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s -O3")

include_directories(.)

add_executable(lab12_UnoAi
        AI.cpp
        AI.h
        Card.cpp
        Card.h
        FireAI.cpp
        FireAI.h
        main.cpp
        Player.cpp
        Player.h
        TestAI.cpp
        TestAI.h)
