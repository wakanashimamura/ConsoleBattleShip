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

#include <fstream>
#include <unordered_map>
#include <variant>

class Statistics {
 public:
  enum class PlayerLevel {
    Level1 = 1,
    Level2,
    Level3,
    Level4,
    Level5,
    Level6,
    Level7,
    Level8,
    Level9,
    Level10,
  };

  enum class StatisticKey { matchRating, games, wins, losses, nextLevel };

  Statistics();

  void UpdateWinnerStatus(int MR);
  void UpdateLoserStatus(int MR);

  const PlayerLevel& GetLevel() const { return level; }
  const std::unordered_map<StatisticKey, int>& GetStatistics() const { return statistics; }

  void Write(std::ofstream& fileStream) const;
  void Read(std::ifstream& fileStream);

 private:
  void UpdateLevel();
  void UpdateNextLevelMR();

  void AddValue(int& currentValue, int amountToAdd);
  void SubtractValue(int& currentValue, int amountToSubtract);

  PlayerLevel level                                = PlayerLevel::Level3;  // Level of the player
  std::unordered_map<StatisticKey, int> statistics = {
      {StatisticKey::matchRating, 901},  // Match rating of the player
      {StatisticKey::games, 0},          // Total number of games played
      {StatisticKey::wins, 0},           // Number of games won
      {StatisticKey::losses, 0},         // Number of games lost
      {StatisticKey::nextLevel, 0},      // How many MR the next level

  };

  static const std::unordered_map<PlayerLevel, std::pair<int, int>> LevelMap;
};