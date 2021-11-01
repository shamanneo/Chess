#pragma once
#include "State.h"

class CChessGame ; 
class CBlackReady : public CState
{
    private :
        CChessGame *m_chess_game ; 
    public :
        CBlackReady(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board) ; 
        virtual bool WhiteSelect(int x, int y) override ;
        virtual bool WhiteMove(int x, int y) override ;
        virtual bool BlackSelect(int x, int y) override ;
        virtual bool BlackMove(int x, int y) override ;
} ;

