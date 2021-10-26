#pragma once
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>

class CChessBoard ; 
class CPaintChessBoard
{
    private :
        HWND m_hwnd ; 
        HDC m_hdc ; 
        Gdiplus::Graphics m_graphics ;  
        CChessBoard *m_chessboard ; 
        const int m_size = 60 ; 

    public :
        CPaintChessBoard(HWND hwnd, CChessBoard *chessboard) ;
        ~CPaintChessBoard() ;
        void DrawBoard() ; 
        void DrawSmallRect(int x, int y) ; 
        void MarkPos(int x, int y) ; 
        void ErasePos(int x, int y) ; 
} ;
