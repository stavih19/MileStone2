cmake_minimum_required(VERSION 3.15)
project(Milestone2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")
add_executable(Milestone2 CacheManager.h ClientHandler.h MyserialServer.cpp MyserialServer.h MyTestClientHandler.cpp MyTestClientHandler.h server_side.h StringReverser.cpp StringReverser.h Solver.h FileCacheManager.cpp FileCacheManager.h main.cpp boot.h Searcher.h Searchable.h State.h)