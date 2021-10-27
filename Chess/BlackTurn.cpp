#include "BlackTurn.h"
#include "ChessGame.h"

CBlackTurn::CBlackTurn(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board)
    : CState(chess_board, paint_board) 
{
    m_chess_game = chess_game ; 
}

bool CBlackTurn::CanPicked(CPiece *prev, CPiece *cur)
{
    if (prev == cur)
    {
        return false ;
    }
    else if (cur != nullptr && cur->GetColor() == 1) // is white?
    {
        return false ;
    }
    else
    {
        if (prev != nullptr)
        {
            GetPaintBoard()->ErasePos(prev->GetX(), prev->GetY()) ;
        }
        GetPaintBoard()->MarkPos(cur->GetX(), cur->GetY()) ;
        return true ;
    }
}

void CBlackTurn::WhiteSelect(int x, int y)
{
    return ; 
}

void CBlackTurn::WhiteMove(int x, int y)
{
    return ; 
}

void CBlackTurn::BlackSelect(int x, int y)
{
    CPiece *prev = m_chess_game->GetPrevPiece() ;
    CPiece *cur = GetChessBoard()->GetPiece(x, y) ;
    if (CanPicked(prev, cur) == true)
    {
        m_chess_game->SetState(m_chess_game->GetWhiteReadyState()) ;
    }
}

void CBlackTurn::BlackMove(int x, int y)
{
    return ; 
}

