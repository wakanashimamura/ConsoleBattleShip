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

#include "GameException.h"

GameException::GameException(const std::string& errorMessage, const std::source_location& location)
    : errorMessage(errorMessage),
      functionName(location.function_name()),
      fileName(location.file_name()),
      lineNumber(location.line()) {}

const std::string& GameException::GetErrorMessage() const {
  return errorMessage;
}

const std::string& GameException::GetFunctionName() const {
  return functionName;
}

const std::string& GameException::GetFileName() const {
  return fileName;
}

int GameException::GetLineNumber() const {
  return lineNumber;
}

const char* GameException::what() const noexcept {
  return errorMessage.c_str();
}

void RenderErorr(const std::exception& exception) {
  Console::ClearScreen();

  const GameException* gameException = dynamic_cast<const GameException*>(&exception);

  if (gameException != nullptr) {
    std::cout << "Game exception was thrown!\n";
    std::cout << "Message  |" << gameException->GetErrorMessage() << std::endl;
    std::cout << "Function |" << gameException->GetFunctionName() << std::endl;
    std::cout << "File     |" << gameException->GetFileName() << std::endl;
    std::cout << "Line #   |" << gameException->GetLineNumber() << std::endl;
    std::cout << std::endl;
  } else {
    Console::ChangeColor(Console::Color::Red);
    std::cout << "Some undefined exception was thrown!" << std::endl;
    ;
    Console::ChangeColor(Console::Color::Cyan);
    std::cout << "Message:  " << exception.what() << std::endl;
  }

  Console::PauseApplication();
  exit(-1);
}