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

class InputManager {
 public:
  InputManager() = delete;

  enum class Key {
    None = -1,
    Tab,
    Enter,
    Escape,
    ArrowUp,
    ArrowLeft,
    ArrowRight,
    ArrowDown,
    PageDown,
    PageUp,
    Delete,
    A,
    D,
    E,
    Q,
    S,
    W
  };

  static void ClearBuffer();
  static bool UserPressedKey();
  static Key PressedKey();
  static int Getch();

 private:
  static Key pressedKey;
};