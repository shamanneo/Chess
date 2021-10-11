#pragma once
#include "CState.h"
#include "CChessBoard.h"

extern CChessBoard chess_board ;

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

