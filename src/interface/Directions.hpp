#ifndef STAYNORMAL_DIRECTIONS_HPP
#define STAYNORMAL_DIRECTIONS_HPP

enum Direction{None, Up, Down, Left, LeftUp, LeftDown, Right, RightUp, RightDown, Size, Error};

Direction operator!(Direction direction);

static_assert( Up + Left == LeftUp );
static_assert( Up + Right == RightUp );
static_assert( Down + Left == LeftDown );
static_assert( Down + Right == RightDown );

enum Orientation{Vertical, Horizontal};

#endif //STAYNORMAL_DIRECTIONS_HPP
