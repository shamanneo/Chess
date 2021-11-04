#pragma once
#include "PaintChessBoard.h"

class CPiece ; 
class CChessBoard
{
    private :
        CPiece *m_chess_board[8][8] ; // chess logic. 
    public :
        CChessBoard(HWND hwnd) ; 
        ~CChessBoard() ; 
        void Clear() ; 
        void Reset(HWND hwnd) ;
        inline CPiece *GetPiece(int x, int y) const ;
        void SetPieces(int cur_x, int cur_y, int tar_x, int tar_y, CPiece &piece) ;
} ;

inline CPiece *CChessBoard::GetPiece(int x, int y) const // inline 
{
    return m_chess_board[x][y] ;
}