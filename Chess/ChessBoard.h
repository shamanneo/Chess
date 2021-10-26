#pragma once
#include <cmath>
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>
#include "Piece.h"

class CChessBoard
{
    private :
        CPiece *m_chess_board[8][8] ; // chess logic. 
    public :
        CChessBoard() ; 
        void Reset() ;
        void DrawBoard(HWND hWnd, HDC hdc) ;
        inline CPiece *GetPiece(int x, int y) const 
        {
            return m_chess_board[x][y] ; 
        }
        void SetPieces(int tar_x, int tar_y, int cur_x, int cur_y, CPiece &piece) ; 
        void DrawSmallRect(HDC hdc, int x, int y) const ;
        void DrawCurrentPos(int x, int y) const ;
        void ErasePrevPos(int x, int y) const ; 
} ;

