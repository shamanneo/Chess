#pragma once
#include <windowsx.h>
#include "ChessBoard.h"
#include "ChessGame.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_cb ;
        CChessGame *m_cg ; 
    protected :
        void OnCommand(HWND hwnd, WPARAM wParam) ;
        void OnPaint(HWND hwnd) ; 
        void OnLButtonDown(HWND hwnd, LPARAM lParam) ;
        void OnDestory() ;
    public :
        CChessBoardWindow(HWND hwnd) ; 
        ~CChessBoardWindow() ;
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        void Reset(HWND hwnd) ;
} ;

