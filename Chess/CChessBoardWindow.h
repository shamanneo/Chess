#pragma once
#include "CChessBoard.h"
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
        CChessBoardWindow()
        {
            m_cb = new CChessBoard ; 
        }
        inline CChessBoard *GetChessBoard() const  
        {
            return m_cb ;
        }
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        
} ;

