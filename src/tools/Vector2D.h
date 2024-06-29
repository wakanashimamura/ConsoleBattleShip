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

template <typename _Ty>
struct Vector2DBase {
  _Ty x;
  _Ty y;
};

template <typename _Ty>
inline bool operator==(const Vector2DBase<_Ty>& left, const Vector2DBase<_Ty>& right) {
  return left.x == right.x && left.y == right.y;
}

template <typename _Ty>
inline bool operator!=(const Vector2DBase<_Ty>& left, const Vector2DBase<_Ty>& right) {
  return left.x != right.x && left.y != right.y;
}

template <typename _Ty>
inline Vector2DBase<_Ty>& operator++(Vector2DBase<_Ty>& vector2D) {
  ++vector2D.x;
  ++vector2D.y;
  return vector2D;
}

template <typename _Ty>
inline Vector2DBase<_Ty> operator++(Vector2DBase<_Ty>& vector2D, int) {
  Vector2DBase<_Ty> temp(vector2D);
  ++vector2D.x;
  ++vector2D.y;
  return temp;
}

template <typename _Ty>
inline Vector2DBase<_Ty>& operator--(Vector2DBase<_Ty>& vector2D) {
  --vector2D.x;
  --vector2D.y;
  return vector2D;
}

template <typename _Ty>
inline Vector2DBase<_Ty> operator--(Vector2DBase<_Ty>& vector2D, int) {
  Vector2DBase<_Ty> temp(vector2D);
  --vector2D.x;
  --vector2D.y;
  return temp;
}

using Vector2DI = Vector2DBase<int>;
using Vector2D  = Vector2DBase<size_t>;
using Vector2DD = Vector2DBase<double>;