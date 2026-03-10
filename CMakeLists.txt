cmake_minimum_required(VERSION 3.4...3.18)
project(kmNet LANGUAGES CXX)
add_subdirectory(pybind11-master)


pybind11_add_module(kmNet kmNetModule.cpp kmboxNet.cpp HidTable.h kmboxNet.h)