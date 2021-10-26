#pragma once
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>

class CChessBoard ; 
class CFaintChessBoard
{
    private :
        HWND m_hwnd ; 
        HDC m_hdc ; 
        Gdiplus::Graphics m_graphics ;  
        CChessBoard *m_chessboard ; 
        const int m_size = 60 ; 

    public :
        CFaintChessBoard(HWND hwnd, CChessBoard *chessboard) ; 
        ~CFaintChessBoard() ; 
        void DrawBoard() ; 
        void DrawSmallRect(int x, int y) ; 
        void MarkPos(int x, int y) ; 
        void ErasePos(int x, int y) ; 
} ;
