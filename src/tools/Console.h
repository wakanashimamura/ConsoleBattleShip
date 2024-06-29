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

#include <string>
#include <Windows.h>

#undef max

class Console {
 public:
  Console() = delete;

  enum class Color {
    Blue         = 1,
    Green        = 2,
    Cyan         = 3,
    Red          = 4,
    Magenta      = 5,
    LightBlue    = 9,
    LightGreen   = 10,
    LightCyan    = 11,
    LightRed     = 12,
    LightMagenta = 13,
    White        = 15,
    Whiteandblue = 23
  };

  static void StopFor(unsigned milliseconds);
  static void ResetCursorPosition();
  static void SetCursorPosition(size_t x, size_t y);
  static std::pair<short, short> GetCursorPosition();
  static void HideCursor();
  static void SetWindowSize(SHORT width, SHORT height);
  static void SetFontSettings(SHORT fontSize, const std::wstring& fontName);
  static void DisableScrollBars();
  static void DisableMaximizeButton();
  static void DisableWindowResizing();
  static void SetTitle(const std::string& title);

  static void ClearScreen();
  static void PauseApplication();
  static void ChangeColor(Color color);

 private:
  static HANDLE consoleHandle;
  static HWND consoleWindow;
};