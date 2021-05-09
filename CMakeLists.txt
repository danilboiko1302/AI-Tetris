cmake_minimum_required(VERSION 3.19)
project(AI_Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(AI_Tetris src/main.cpp src/Shape.cpp src/Shape.h src/Game.cpp src/Game.h src/AI.cpp src/AI.h src/AIGame.cpp src/AIGame.h src/Array.h src/Sequence.h)