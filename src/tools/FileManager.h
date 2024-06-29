// ================================================================================================
//
// ConsoleBattleShip - classic game of “Battleship” implemented in the console.
//
// Copyright (C) 2024 Wakana Shimamura
//
// This file is part of ConsoleBattleShip.
//
// ConsoleBattleShip is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ConsoleBattleShip is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ConsoleBattleShip. If not, see <https://www.gnu.org/licenses/>.
//
// Repository: https://github.com/wakanashimamura/ConsoleBattleShip
//
// ================================================================================================

#pragma once

#include "../Game/Enumerations.h"

#include <string>

class Player;

class FileManager {
 public:
  FileManager() = delete;

  static bool ReadTextFromFile(const std::string& fileName, std::string& content);

  static bool ReadPlayerFromBinaryFile(const std::string& fileName, Player& player);

  static bool ReadGameModeFromBinaryFile(const std::string& fileName, GameMode& player);

  static bool WriteTextInFile(const std::string& fileName, std::string& content);

  static bool WritePlayerInBinaryFile(const std::string& fileName, const Player& player);

  static bool WriteGameModeInBinaryFile(const std::string& fileName, const GameMode& gameMode);
};