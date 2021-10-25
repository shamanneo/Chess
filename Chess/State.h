#pragma once
#include "Piece.h"
#include "ChessBoard.h"

class CState
{
    public :
        virtual CPiece *Pick(CPiece *prev, int x, int y)
        {
            return nullptr ;
        }
        virtual CPiece *Move(CPiece *prev, int x, int y)
        {
            return nullptr ;
        }
} ;

