#pragma once
#include <Windows.h>
#include <windowsx.h>
#include "ChessBoard.h"
#include "ChessGame.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_cb ;
        CPaintChessBoard *m_fcb ; 
    protected :
        void OnPaint(HWND hwnd) ;
        void OnLButtonDown(LPARAM lParam) ;
        void OnDestory() ;
    public :
        CChessBoardWindow(HWND hwnd) ; 
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
} ;

