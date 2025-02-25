# CMake configuration for PokerHands library
add_library(PokerHandsLib 
              Window.cpp
               Game.cpp)

# Ustawienie katalogów nagłówkowych dla tej biblioteki
target_include_directories(PokerHandsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})