cmake_minimum_required(VERSION 3.10)
project(MovieRecommender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Main
    src/main.cpp 
    src/Movie.h
    src/Movie.cpp
    src/BTree.h
    src/BTree.cpp
    src/MaxHeap.cpp
    src/MaxHeap.h
)

add_executable(Parser
        src/Database/DatabaseParser.cpp
)