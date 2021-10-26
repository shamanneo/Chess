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
        virtual void WhiteSelect(int x, int y) ;
        virtual void WhiteMove(int x, int y) ;
        virtual void BlackSelect(int x, int y) ;
        virtual void BlackMove(int x, int y) ;
} ;

