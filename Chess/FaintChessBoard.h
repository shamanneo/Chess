#pragma once
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>

class CFaintChessBoard
{
    private :
        HWND m_hwnd ; 
        HDC m_hdc ; 
        Gdiplus::Graphics m_graphics ;  
        const int m_size = 60 ; 

    public :
        CFaintChessBoard(HWND hwnd) ; 
        ~CFaintChessBoard() ; 
        void DrawBoard() ; 
        void DrawSmallRect(int x, int y) ; 
        void MarkPos(int x, int y) ; 
        void ErasePos(int x, int y) ; 
} ;
