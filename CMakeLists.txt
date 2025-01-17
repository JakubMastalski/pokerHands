cmake_minimum_required(VERSION 3.18)

project(PokerHands)

set(CMAKE_CXX_STANDARD 20)

# Główna aplikacja
add_executable(${PROJECT_NAME} main.cpp)

# Dodanie podprojektów
add_subdirectory(PokerHands)
add_subdirectory(tests)

# Ustawienie katalogu dla bibliotek
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Konfiguracja zależna od kompilatora
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GNU compiler: ${CMAKE_CXX_COMPILER_ID}")
    set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/GCC/SFML-2.6.1/include)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/GCC/SFML-2.6.1/lib/cmake/SFML)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Using MSVC compiler: ${CMAKE_CXX_COMPILER_ID}")
    set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/MSVC/SFML-2.6.1/include)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/MSVC/SFML-2.6.1/lib/cmake/SFML)
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

# Znalezienie SFML
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS system window graphics audio network)

# Dodanie katalogów nagłówkowych
include_directories(${CMAKE_SOURCE_DIR}/PokerHands)

# Dodanie bibliotek do linkowania
target_link_libraries(${PROJECT_NAME} PRIVATE PokerHandsLib sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
