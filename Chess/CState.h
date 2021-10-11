#pragma once
#include "CPiece.h"
#include "CChessBoard.h"

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

