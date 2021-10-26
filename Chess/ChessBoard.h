#pragma once
#include <cmath>
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>
#include "Piece.h"
#include "PaintChessBoard.h"

class CChessBoard
{
    private :
        CPiece *m_chess_board[8][8] ; // chess logic. 
        CPaintChessBoard *m_paint_board ; 
    public :
        CChessBoard() ; 
        void Clear() ; 
        void Reset() ;
        inline CPiece *GetPiece(int x, int y) const ;
        void SetPieces(int tar_x, int tar_y, int cur_x, int cur_y, CPiece &piece) ; 
        CPaintChessBoard *GetPaintBoard() const ; 
} ;

