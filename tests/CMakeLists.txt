# Ustaw minimaln  wersj  CMake
cmake_minimum_required(VERSION 3.18)

# Dodaj bibliotek  Google Test
add_subdirectory(libs/googletest)

# Tworzenie pliku wykonywalnego dla test w
add_executable(tests main_tests.cpp)

# Ustaw lokalizacj  SFML w zale no ci od kompilatora
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GNU compiler: ${CMAKE_CXX_COMPILER_ID}")
    set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/GCC/SFML-2.6.1/include)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/GCC/SFML-2.6.1/lib/cmake/SFML)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Using MSVC compiler: ${CMAKE_CXX_COMPILER_ID}")
    set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/MSVC/SFML-2.6.1/include)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/MSVC/SFML-2.6.1/lib/cmake/SFML)
endif()

set(SFML_STATIC_LIBRARIES TRUE)

# Znajd  pakiet SFML
find_package(SFML REQUIRED COMPONENTS system window graphics audio network)

# Ustaw katalogi do przeszukiwania nag  wk w
include_directories(${SFML_INCLUDE_DIR})

# Linkowanie test w z bibliotekami SFML i Google Test
target_link_libraries(tests PRIVATE gtest gtest_main sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# W  czenie funkcji testowania
enable_testing()

# Rejestracja test w w CTest
add_test(NAME tests COMMAND tests)