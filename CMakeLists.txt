cmake_minimum_required(VERSION 3.17)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShoppingList main.cpp Product.cpp Product.h List.cpp List.h)