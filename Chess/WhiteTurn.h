#pragma once
#include "State.h"

class CChessGame ; 
class CWhiteTurn : public CState
{
    private : 
        CChessGame *m_chess_game ;
    public : 
        CWhiteTurn(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board) ; 
        bool CanPicked(CPiece *prev, CPiece *cur) ;
        virtual void WhiteSelect(int x, int y) override ;
        virtual void WhiteMove(int x, int y) override ;
        virtual void BlackSelect(int x, int y) override ;
        virtual void BlackMove(int x, int y) override ;
} ;

