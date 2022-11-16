#include "Directions.hpp"


static Direction inverse(Direction direction)
{
    switch (direction) {
        case None:
            return Size;
        case Up:
            return Down;
        case Down:
            return Up;
        case Left:
            return Right;
        case LeftUp:
            return RightDown;
        case LeftDown:
            return RightUp;
        case Right:
            return Left;
        case RightUp:
            return LeftDown;
        case RightDown:
            return LeftUp;
        case Size:
            return None;
        case Error:
            return Error;
            break;
    }
}

Direction operator!(Direction direction)
{ return inverse(direction); }
