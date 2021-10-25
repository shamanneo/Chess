#pragma once
#include "State.h"

class CChessGame ;
class CBlackTurn : public CState
{
    private :
        CChessGame *m_chess_game ; 
        bool IsPicked(CPiece *prev, CPiece *cur) ; 
    public :
        CBlackTurn(CChessGame *chess_game)
        {
            m_chess_game = chess_game ; 
        }
        virtual CPiece *Pick(CPiece *prev, int x, int y) ; 
} ;


