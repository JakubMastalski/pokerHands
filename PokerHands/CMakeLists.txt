add_subdirectory(Core)
add_subdirectory(Screen)
add_subdirectory(Tools)
add_subdirectory(Manager)

# Create library which link all modules
add_library(PokerHandsLib INTERFACE)

# Link all modules to PokerHandsLib
target_link_libraries(PokerHandsLib INTERFACE CoreModule ManagerModule ToolsModule ScreenModule)