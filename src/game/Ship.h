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

#include "../Tools/Vector2D.h"

#include <vector>

class Ship {
 public:
  enum class ShipSize { TorpedoBoats, Destroyers, Cruisers, BattleShip };

  enum class Direction { None = -1, Horizontal, Vertical };

  Ship(ShipSize shipSize);

  void AutoPlace();

  bool MoveUp();
  bool MoveLeft();
  bool MoveRight();
  bool MoveDown();

  void SwitchOrientation();

  void RestoreDefault();

  void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
  void SetIsPlaced(bool isPlaced) { this->isPlaced = isPlaced; }

  const std::vector<Vector2D>& GetPosition() const { return positions; }
  const Direction& GetOrientation() const { return orientation; }
  const ShipSize& GetShipSize() const { return shipSize; }
  const bool GetIsAlive() const { return isAlive; }
  const bool GetIsPlaced() const { return isPlaced; }

 private:
  std::vector<Vector2D> positions;
  ShipSize shipSize;
  Direction orientation = Direction::Vertical;

  bool isAlive  = true;
  bool isPlaced = false;

  static const Vector2D STARTING_COORDINATE;
  static const size_t BOARD_SIZE;
};