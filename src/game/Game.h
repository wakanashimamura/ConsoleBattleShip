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

#include "Bot.h"
#include "Player.h"
#include "UserInterface.h"

class Game {
 public:
  Game();

  void LoadGame();

  void SetIsLoadGame(bool isLoadGame) { this->isLoadGame = isLoadGame; }
  void SetIsGameRunning(bool isGameRunning) { this->isGameRunning = isGameRunning; }
  void SetGameMode(GameMode gameMode) { this->gameMode = gameMode; }

  bool GetIsLoadGame() const { return isLoadGame; }
  bool GetIsGameRunning() const { return isGameRunning; }
  GameMode GetGameMode() const { return gameMode; }
  void SaveData() const;
  void ReadData();

  static const std::string PLAYER1_FILE_NAME;
  static const std::string PLAYER2_FILE_NAME;
  static const std::string BOT_FILE_NAME;
  static const std::string GAME_MODE_FILE_NAME;

 private:
  void Menu();
  void StartGame(Player& p1, Player& p2);

  void EndGame();

  void DeclareWinner(Player& winner, Player& losses);

  bool isLoadGame;
  bool isGameRunning;
  GameMode gameMode;

  Player player1;
  Player player2;
  Bot bot;
  UserInterface& userInterface;
};