#pragma once
#include "State.h"

class CChessGame ;
class CWhiteReady : public CState
{
    private :
        CChessGame *m_chess_game ; 
        CChessBoard *m_chess_board ; 
    public :
        CWhiteReady(CChessGame *chess_game, CChessBoard *chess_board) ; 
        virtual void WhiteSelect(int x, int y) override ;
        virtual void WhiteMove(int x, int y) override ;
        virtual void BlackSelect(int x, int y) override ;
        virtual void BlackMove(int x, int y) override ;
} ;

