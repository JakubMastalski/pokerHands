# Create static library for module Core
add_library(ScreenModule STATIC Window.cpp 
                                BaseScreen.cpp
                                MenuScreen.cpp
                                GameScreen.cpp)

# Add include directories for search
include_directories(${POKER_HANDS_DIR} ${SFML_INCLUDE_DIR})

# Link all dependencies for CoreModule
target_link_libraries(ScreenModule PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)