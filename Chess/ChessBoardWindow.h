#pragma once
#include <windowsx.h>
#include "ChessBoard.h"
#include "ChessGame.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_cb ;
    protected :
        void OnPaint(HWND hwnd) ;
        void OnLButtonDown(HWND hwnd, LPARAM lParam) ;
        void OnDestory() ;
    public :
        CChessBoardWindow(HWND hwnd) ; 
        ~CChessBoardWindow() ;
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
} ;

