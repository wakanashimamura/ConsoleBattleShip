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

#include "FileManager.h"

#include "../Game/Player.h"

#include <fstream>

bool FileManager::ReadTextFromFile(const std::string& fileName, std::string& content) {
  std::ifstream fileStream(fileName);

  if (!fileStream.is_open()) {
    return false;
  }

  std::string textLine;

  for (; !fileStream.eof();) {
    std::getline(fileStream, textLine);
    textLine.push_back('\n');
    content += textLine;
  }

  return true;
}

bool FileManager::ReadPlayerFromBinaryFile(const std::string& fileName, Player& player) {
  std::ifstream fileStream(fileName);

  if (!fileStream.is_open()) {
    return false;
  }

  player.Read(fileStream);

  return true;
}

bool FileManager::ReadGameModeFromBinaryFile(const std::string& fileName, GameMode& gameMode) {
  std::ifstream fileStream(fileName);

  if (!fileStream.is_open()) {
    return false;
  }

  int gameModeInt;
  fileStream.read(reinterpret_cast<char*>(&gameModeInt), sizeof(gameModeInt));
  gameMode = static_cast<GameMode>(gameModeInt);

  return true;
}

bool FileManager::WriteTextInFile(const std::string& fileName, std::string& content) {
  std::ofstream fileStream(fileName);

  if (!fileStream.is_open()) {
    return false;
  }

  fileStream << content;

  return true;
}

bool FileManager::WritePlayerInBinaryFile(const std::string& fileName, const Player& player) {
  std::ofstream fileStream(fileName);

  if (!fileStream.is_open()) {
    return false;
  }

  player.Write(fileStream);

  return true;
}

bool FileManager::WriteGameModeInBinaryFile(const std::string& fileName, const GameMode& gameMode) {
  std::ofstream fileStream(fileName);

  if (!fileStream.is_open()) {
    return false;
  }

  int gameModeInt = static_cast<int>(gameMode);
  fileStream.write(reinterpret_cast<const char*>(&gameModeInt), sizeof(gameModeInt));

  return true;
}