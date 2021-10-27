#pragma once
#include "State.h"

class CChessGame ; 
class CBlackReady : public CState
{
    private :
        CChessGame *m_chess_game ; 
    public :
        CBlackReady(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board) ; 
        virtual void WhiteSelect(int x, int y) override ;
        virtual void WhiteMove(int x, int y) override ;
        virtual void BlackSelect(int x, int y) override ;
        virtual void BlackMove(int x, int y) override ;
} ;

