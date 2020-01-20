cmake_minimum_required(VERSION 3.15)
project(Milestone2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")
add_executable(Milestone2 ServersInterfaces/CacheManager.h ServersInterfaces/ClientHandler.h MyserialServer.cpp MyserialServer.h MyTestClientHandler.cpp MyTestClientHandler.h ServersInterfaces/server_side.h StringReverser.cpp StringReverser.h ServersInterfaces/Solver.h FileCacheManager.cpp FileCacheManager.h main.cpp ServersInterfaces/boot.h Searchable.h State.h Matrix.cpp Matrix.h Searcher.h CellMatrix.h BestFirstSearch.cpp BestFirstSearch.h PathInMatrix.cpp PathInMatrix.h MatrixCLientHandler.cpp MatrixCLientHandler.h MyParallelServer.cpp MyParallelServer.h)