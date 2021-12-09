#pragma once
#include <memory>
#include <stack>
#include <windowsx.h>
#include "ChessBoard.h"
#include "ChessGame.h"

class CChessBoardWindow
{
    private :
        CChessBoard *m_cb ;
        CChessGame *m_cg ; 
        typename std::stack<std::shared_ptr<int>> m_arr_stack ; 
        bool m_is_white_player ; 
    protected :
        void OnCommand(HWND hwnd, WPARAM wParam) ;
        void OnPaint(HWND hwnd) ; 
        void OnLButtonDown(HWND hwnd, LPARAM lParam) ;
        void OnDestory() ;
    public :
        CChessBoardWindow(HWND hwnd, bool is_white = true) ; 
        ~CChessBoardWindow() ;
    public :
        LRESULT ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        void Save() ; 
        void Reset(HWND hwnd) ;
        void Undo(HWND hwnd) ;
        void Change(HWND hwnd) ;
} ;

