#pragma once
#include "State.h"

class CChessGame ; 
class CWhiteTurn : public CState
{
    private : 
        CChessGame *m_chess_game ;
    public : 
        CWhiteTurn(CChessGame *chess_game, CChessBoard *chess_board, HWND hwnd) ; 
        bool CanPicked(CPiece *prev, CPiece *cur) ;
        virtual bool WhiteSelect(int x, int y) override ;
        virtual bool WhiteMove(int x, int y) override ;
        virtual bool BlackSelect(int x, int y) override ;
        virtual bool BlackMove(int x, int y) override ;
} ;

