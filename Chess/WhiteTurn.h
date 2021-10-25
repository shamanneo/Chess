#pragma once
#include "State.h"

class CChessGame ; 
class CWhiteTurn : public CState
{
    private : 
        CChessGame *m_chess_game ;
        bool IsPicked(CPiece *prev, CPiece *cur) ;
    public : 
        CWhiteTurn(CChessGame *chess_game)
        {
            m_chess_game = chess_game ; 
        }
        virtual CPiece *Pick(CPiece *prev, int x, int y) ;
} ;

