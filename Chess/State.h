#pragma once
#include "Piece.h"

class CState
{
    private :
        CChessBoard *m_chess_board ; 
        HWND m_hwnd ;
    public :
        CState(CChessBoard *chess_board, HWND hwnd) ; 
    public :
        virtual bool WhiteSelect(int x, int y) ;
        virtual bool WhiteMove(int x, int y) ;
        virtual bool BlackSelect(int x, int y) ;
        virtual bool BlackMove(int x, int y) ;
        CChessBoard *GetChessBoard() const ;
        HWND Gethwnd() const ; 
} ;

