cmake_minimum_required(VERSION 3.14)

project(tic-tac-toe-server LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

add_executable(tic-tac-toe-server
  main.cpp
  cell.h cell.cpp
  board.h board.cpp
  player.h player.cpp
  game.h game.cpp
  turn.h turn.cpp
  lobby.h lobby.cpp
  server.h server.cpp
  connection_settings.h
  game_settings.h game_settings.cpp
  lobby_controller.h lobby_controller.cpp
  board_size.h
)

target_link_libraries(tic-tac-toe-server Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(tic-tac-toe-server Qt6::Network)
