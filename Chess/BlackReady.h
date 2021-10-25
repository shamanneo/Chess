#pragma once
#include "State.h"

class CChessGame ; 
class CBlackReady : public CState
{
    private :
        CChessGame *m_chess_game ; 
    public :
        CBlackReady(CChessGame *chess_game)
        {
            m_chess_game = chess_game ;
        }
        virtual CPiece *Move(CPiece *prev, int x, int y) ; 
} ;

