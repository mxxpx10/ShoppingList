cmake_minimum_required(VERSION 3.17)
project(PodrazaMonika-etap2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PodrazaMonika-etap2 main.cpp Product.cpp Product.h List.cpp List.h SoldByKilograms.cpp SoldByKilograms.h SoldByPiece.cpp SoldByPiece.h SoldByLiters.h SoldByLiters.cpp)