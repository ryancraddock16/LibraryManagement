cmake_minimum_required(VERSION 3.27)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagement main.cpp
        Book.h
        Book.cpp
        Inventory.cpp
        Inventory.h
        LibraryHash.cpp
        LibraryHash.h
        Librarian.cpp
        Librarian.h
)
