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

#include "Console.h"

#include <exception>
#include <iostream>
#include <source_location>

class GameException : public std::exception {
 public:
  GameException(
      const std::string& errorMessage      = "Error",
      const std::source_location& location = std::source_location::current()
  );

  const std::string& GetErrorMessage() const;
  const std::string& GetFunctionName() const;
  const std::string& GetFileName() const;
  int GetLineNumber() const;

  virtual const char* what() const noexcept override;

 private:
  std::string errorMessage;
  std::string fileName;
  std::string functionName;
  int lineNumber;
};

void RenderErorr(const std::exception& exception);