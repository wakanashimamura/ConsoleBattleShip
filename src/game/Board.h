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

#include "../Tools/Console.h"
#include "Enumerations.h"
#include "Ship.h"

#include <array>
#include <string>
#include <unordered_map>

class Board {
 public:
  static constexpr size_t BOARD_SIZE = 10;

  using GameBoard = std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>;
  using ShipMap   = std::unordered_multimap<Ship::ShipSize, Ship>;

  enum class BoardSymbol {
    EmptySymbol = '-',  // Empty cell
    ShipSymbol  = '0',  // Ship
    MissSymbol  = '/',  // Miss
    HitSymbol   = 'X'   // Hit
  };

  struct Color {
    Console::Color emptyColor;
    Console::Color shipColor;
    Console::Color missColor;
    Console::Color hitColor;
  };

  Board();

  // ------------------------------------------------------------------------
  // -------------------------- BOARD SETUP METHODS -------------------------

  bool SetupPlayerShips(const std::string& playerName);
  void AutoPlaceShips();

  void ResetToDefaultState();

  void MarkShipAsDestroyed();
  void UpdateAllAliveShipsStatus();

  int GetAliveShipsCount() const;

  // ------------------------------------------------------------------------
  // -------------------------------- GETTERS -------------------------------

  std::vector<Vector2D> GetValidShotPositions() const;

  const GameBoard& GetGameBoard() const { return gameBoard; }
  const GameBoard& GetHiddenGameBoard() const { return hiddenGameBoard; }

  ShotStatus RegisterShot(Vector2D shot);

  static constexpr Color symbolColors = {
      Console::Color::LightBlue, Console::Color::Green, Console::Color::Cyan, Console::Color::Red
  };

 private:
  // -------------------------------------------------------------------------
  // --------------------------- BOARD MANAGEMENT ----------------------------

  void InitializeBoard();

  Ship* FindShipBySize(Ship::ShipSize shipSize);

  void MoveShip(Ship& ship, Direction direction);

  void SetupShipBySize(Ship::ShipSize shipSize, const std::string& playerName);
  void SetupShip(Ship& ship, const std::string& playerName, bool editMode = false);

  std::pair<Vector2D, Vector2D> GetSurroundingArea(const Ship& ship) const;

  // -------------------------------------------------------------------------
  // ----------------------------- EDIT METHODS ------------------------------

  void EditMode(const std::string& playerName);
  void SwitchOrientation(Ship& ship);

  // -------------------------------------------------------------------------
  // -------------------------  POSITION VALIDATION --------------------------

  bool IsPositionFree(const Ship& ship) const;
  bool ValidateShipPosition(const Ship& ship) const;

  // -------------------------------------------------------------------------
  // -------------------------- SUPPORTIVE METHODS ---------------------------

  void UpdateShipPositionOnBoard(
      const Ship& ship, BoardSymbol boardSymbol = BoardSymbol::ShipSymbol
  );

  void RemoveShip(Ship& ship);
  void RemoveShips();

  bool CanSaveBoardState();

  void UpdateShipAliveStatus(Ship& ship);

  // -------------------------------------------------------------------------
  // --------------------------------- DATA ----------------------------------

  GameBoard gameBoard;
  GameBoard hiddenGameBoard;

  ShipMap ships = {
      {Ship::ShipSize::BattleShip, Ship(Ship::ShipSize::BattleShip)},

      {Ship::ShipSize::Cruisers, Ship(Ship::ShipSize::Cruisers)},
      {Ship::ShipSize::Cruisers, Ship(Ship::ShipSize::Cruisers)},

      {Ship::ShipSize::Destroyers, Ship(Ship::ShipSize::Destroyers)},
      {Ship::ShipSize::Destroyers, Ship(Ship::ShipSize::Destroyers)},
      {Ship::ShipSize::Destroyers, Ship(Ship::ShipSize::Destroyers)},

      {Ship::ShipSize::TorpedoBoats, Ship(Ship::ShipSize::TorpedoBoats)},
      {Ship::ShipSize::TorpedoBoats, Ship(Ship::ShipSize::TorpedoBoats)},
      {Ship::ShipSize::TorpedoBoats, Ship(Ship::ShipSize::TorpedoBoats)},
      {Ship::ShipSize::TorpedoBoats, Ship(Ship::ShipSize::TorpedoBoats)},
  };

  static constexpr Vector2D defaultPositionGameBoard{27, 11};
};