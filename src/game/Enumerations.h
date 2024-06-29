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
// clang-format off

#pragma once


enum class GameMode
{
	PlayerVsPlayer,
	PlayerVsBot,
};

enum class ShotStatus
{
	Hit,
	Miss,
	NoneShot
};

enum class MatchStatus
{
	Cancelled,
	WinnerDeclared,
	InProgress  
};

enum class GameAction
{
	Continue,
	End
};

enum class Direction
{
	Up,
	Left,
	Right,
	Down
};

enum class RenderingMode {
	Hidden,
	Visible
};

enum class Screen
{
	Logo,
	Menu,
	Game
};

enum class MenuWindow
{
	MainMenu,
	Statistics,
	Settings,
	SettingsNameChange,
	SettingsGameMode,
	Tutorial
};

enum class MainMenuItem
{
	StartGame,
	Statistics,
	Tutorials,
	Settings,
	Exit
};

enum class ShipsSetupMenuItem
{
	BattleShip,
	Cruisers,
	Destroyers,
	TorpedoBoats,
	RemoveShips,
	Edit,
	Auto,
	Save,
	Exit
};

enum class SettingsMenuItem
{
	NameChange,
	GameMode,
	Exit
};

enum class SettingsNameChangeMenuItem
{
	Player1,
	Player2,
	Exit
};

enum class SettingsGameModeMenuItem
{
	PlayerVsPlayer,
	PlayerVsBot,
	Exit
};

template<typename MenuItemType>
void ChangeMenuItemUp(MenuItemType& item, MenuItemType firstItem, MenuItemType lastItem)
{
	item = (item == firstItem) ? lastItem : MenuItemType(static_cast<int>(item) - 1);
}

template<typename MenuItemType>
void ChangeMenuItemDown(MenuItemType& item, MenuItemType firstItem, MenuItemType lastItem)
{
	item = (item == lastItem) ? firstItem : MenuItemType(static_cast<int>(item) + 1);
}