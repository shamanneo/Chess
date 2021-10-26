#pragma once
#include <Windows.h>
#include "ChessBoard.h"
#include "Chess.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_cb ;
        CFaintChessBoard *m_fcb ; 
    protected :
        void OnPaint(HWND hwnd) ;
        void OnLButtonDown(LPARAM lParam) ;
        void OnDestory() ;
    public :
        CChessBoardWindow(HWND hwnd) ; 
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        
} ;

