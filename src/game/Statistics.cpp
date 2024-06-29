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

#include "Statistics.h"

#include <limits>

const std::unordered_map<Statistics::PlayerLevel, std::pair<int, int>> Statistics::LevelMap = {
    {PlayerLevel::Level1, {0, 500}},
    {PlayerLevel::Level2, {501, 900}},
    {PlayerLevel::Level3, {901, 1300}},
    {PlayerLevel::Level4, {1301, 1800}},
    {PlayerLevel::Level5, {1801, 2400}},
    {PlayerLevel::Level6, {2401, 2800}},
    {PlayerLevel::Level7, {2801, 3100}},
    {PlayerLevel::Level8, {3101, 3300}},
    {PlayerLevel::Level9, {3301, 3500}},
    {PlayerLevel::Level10, {3501, std::numeric_limits<int>::max()}},
};

Statistics::Statistics() {
  UpdateNextLevelMR();
}

void Statistics::UpdateWinnerStatus(int MR) {
  AddValue(statistics.at(StatisticKey::matchRating), MR);

  UpdateLevel();

  AddValue(statistics.at(StatisticKey::games), 1);

  AddValue(statistics.at(StatisticKey::wins), 1);

  UpdateNextLevelMR();
}

void Statistics::UpdateLoserStatus(int MR) {
  SubtractValue(statistics.at(StatisticKey::matchRating), MR);

  UpdateLevel();

  AddValue(statistics.at(StatisticKey::games), 1);

  AddValue(statistics.at(StatisticKey::losses), 1);

  UpdateNextLevelMR();
}

void Statistics::Write(std::ofstream& fileStream) const {
  // - Write Level -
  int levelInt = static_cast<int>(level);
  fileStream.write(reinterpret_cast<const char*>(&levelInt), sizeof(levelInt));

  // - Write statistics -
  std::unordered_map<StatisticKey, int>::size_type mapSize = statistics.size();
  fileStream.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));

  for (const auto& [key, value] : statistics) {
    int KeyInt = static_cast<int>(key);
    fileStream.write(reinterpret_cast<const char*>(&KeyInt), sizeof(KeyInt));
    fileStream.write(reinterpret_cast<const char*>(&value), sizeof(value));
  }
}

void Statistics::Read(std::ifstream& fileStream) {
  // - Read Level -
  int levelInt;
  fileStream.read(reinterpret_cast<char*>(&levelInt), sizeof(levelInt));
  level = static_cast<PlayerLevel>(levelInt);

  // - Read statistics -
  std::unordered_map<StatisticKey, int>::size_type mapSize;
  fileStream.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));
  statistics.clear();

  for (size_t i = 0; i < mapSize; ++i) {
    int KeyInt;
    fileStream.read(reinterpret_cast<char*>(&KeyInt), sizeof(KeyInt));
    StatisticKey key = static_cast<StatisticKey>(KeyInt);

    int value;
    fileStream.read(reinterpret_cast<char*>(&value), sizeof(value));

    statistics[key] = value;
  }
}

void Statistics::UpdateLevel() {
  for (const auto& [level, MR] : LevelMap) {
    if (statistics.at(StatisticKey::matchRating) >= MR.first &&
        statistics.at(StatisticKey::matchRating) <= MR.second) {
      this->level = level;
      break;
    }
  }
}

void Statistics::UpdateNextLevelMR() {
  if (level == PlayerLevel::Level10) {
    statistics.at(StatisticKey::nextLevel) = 0;
  } else {
    statistics.at(StatisticKey::nextLevel) =
        LevelMap.at(PlayerLevel(static_cast<int>(level) + 1)).first -
        statistics.at(StatisticKey::matchRating);
  }
}

void Statistics::AddValue(int& currentValue, int amountToAdd) {
  if (currentValue >= std::numeric_limits<int>::max() - amountToAdd) {
    currentValue = std::numeric_limits<int>::max();
  } else {
    currentValue += amountToAdd;
  }
}

void Statistics::SubtractValue(int& currentValue, int amountToSubtract) {
  if (currentValue - amountToSubtract < 0) {
    currentValue = 0;
  } else {
    currentValue -= amountToSubtract;
  }
}