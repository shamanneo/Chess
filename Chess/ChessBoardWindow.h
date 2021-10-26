#pragma once
#include "ChessBoard.h"
#include "Chess.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_cb ;
    protected :
        void OnPaint(HWND hwnd) ;
        void OnLButtonDown(LPARAM lParam) ;
        void OnDestory() ;
    public :
        CChessBoardWindow() ; 
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        
} ;

