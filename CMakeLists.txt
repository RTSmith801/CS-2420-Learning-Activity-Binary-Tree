cmake_minimum_required(VERSION 3.22)
project(06_Learning_Activity_Binary_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(06_Learning_Activity_Binary_Tree
        BinaryTreeTester.cpp
        BTree.h)
