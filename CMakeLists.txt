cmake_minimum_required(VERSION 3.21)

project(ConsoleBattleShip VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleBattleShip
	src/game/Board.cpp
	src/game/Bot.cpp
	src/game/Game.cpp
	src/game/Player.cpp
	src/game/Ship.cpp
	src/game/Statistics.cpp
	src/game/UserInterface.cpp

	src/tools/Console.cpp
	src/tools/FileManager.cpp
	src/tools/GameException.cpp
	src/tools/InputManager.cpp
	src/tools/Random.cpp

	src/main.cpp
) 

file(COPY "${CMAKE_SOURCE_DIR}/ui"
	DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)