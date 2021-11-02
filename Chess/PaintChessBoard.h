#pragma once
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>

class CPiece ; 
class CChessBoard ; 
class CPaintChessBoard
{
    private :
        HWND m_hwnd ; 
        HDC m_hdc ; 
        Gdiplus::Graphics m_graphics ;  
        const int m_size = 60 ; 
    public :
        CPaintChessBoard(HWND hwnd) ;
        ~CPaintChessBoard() ;
        void DrawBoard(CChessBoard *chess_board) ; 
        void DrawPiece(CPiece *piece, int x, int y) ;
        void DrawSmallRect(int x, int y) ; 
        void MarkPos(int x, int y) ; 
        void ErasePos(int x, int y) ; 
} ;
