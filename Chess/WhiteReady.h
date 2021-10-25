#pragma once
#include "State.h"

class CChessGame ;
class CWhiteReady : public CState
{
    private :
        CChessGame *m_chess_game ; 
    public :
        CWhiteReady(CChessGame *chess_game)
        {
            m_chess_game = chess_game ;
        }
        virtual CPiece *Move(CPiece *prev, int x, int y) ;
} ;

