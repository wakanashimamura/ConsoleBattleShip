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

#include "Enumerations.h"
#include "Player.h"

class Bot : public Player {
 public:
  struct ShipSearchState {
    int aliveShipsCount = 0;
    bool hitDetected    = false;
    Vector2D initialHit{0, 0};
    bool isDirectionFound = false;
    Direction direction   = Direction::Up;
  };

  Bot();

  std::pair<ShotStatus, GameAction> Shot(Player& target) override;
  bool PlaceShips() override;

 private:
  ShipSearchState shipSearchState;
  void GenerateRandomShot(const Player& target);
  void ReverseDirection();
  void UpdateSearchDirection();
  bool TryMoveInDirection();
  void ResetToDefaultShipSearchState();
};