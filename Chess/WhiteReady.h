#pragma once
#include "State.h"

class CChessGame ;
class CWhiteReady : public CState
{
    private :
        CChessGame *m_chess_game ; 
    public :
        CWhiteReady(CChessGame *chess_game, CChessBoard *chess_board, HWND hwnd) ; 
        virtual bool WhiteSelect(int x, int y) override ;
        virtual bool WhiteMove(int x, int y) override ;
        virtual bool BlackSelect(int x, int y) override ;
        virtual bool BlackMove(int x, int y) override ;
} ;

