#pragma once
#include "CChessBoard.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_chess_board ;
    protected :
        void OnPaint() ;
        void OnLButtonDown() ;
        void OnDestory() ;
    public :
        inline CChessBoard *GetChessBoard() const  
        {
            return m_chess_board ; 
        }
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        
} ;

