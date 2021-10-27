#pragma once
#include "PaintChessBoard.h"

class CPiece ; 
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

inline CPiece *CChessBoard::GetPiece(int x, int y) const // inline 
{
    return m_chess_board[x][y] ;
}