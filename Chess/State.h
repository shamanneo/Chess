#pragma once
#include "Piece.h"
#include "ChessBoard.h"

class CState
{
    private :
        CChessBoard *m_chess_board ; 
        CPaintChessBoard *m_paint_board ; 
    public :
        CState(CChessBoard *chess_board, CPaintChessBoard *paint_board) ; 
        virtual void WhiteSelect(int x, int y) ;
        virtual void WhiteMove(int x, int y) ;
        virtual void BlackSelect(int x, int y) ;
        virtual void BlackMove(int x, int y) ;
        CChessBoard *GetChessBoard() const ;
        CPaintChessBoard *GetPaintBoard() const ; 
} ;

