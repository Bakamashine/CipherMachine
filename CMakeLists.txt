cmake_minimum_required(VERSION 3.20)
project(CipherMachine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CipherMachine
    main.cpp
    alph.cpp
    cipher.cpp
    numbers.cpp
    randomizer.cpp
)

target_compile_options(CipherMachine PRIVATE -Wall -fexceptions)

target_compile_definitions(CipherMachine PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(CipherMachine PRIVATE -O2)
    target_link_options(CipherMachine PRIVATE -s)
endif()
