#include "BlackTurn.h"
#include "ChessGame.h"

CBlackTurn::CBlackTurn(CChessGame *chess_game, CChessBoard *chess_board)
{
    m_chess_game = chess_game ; 
    m_chess_board = chess_board ; 
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
            m_chess_board->GetPaintBoard()->ErasePos(prev->GetX(), prev->GetY()) ;
        }
        m_chess_board->GetPaintBoard()->MarkPos(cur->GetX(), cur->GetY()) ;
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
    CPiece *cur = m_chess_board->GetPiece(x, y) ;
    if (CanPicked(prev, cur) == true)
    {
        m_chess_game->SetState(m_chess_game->GetWhiteReadyState()) ;
    }
}

void CBlackTurn::BlackMove(int x, int y)
{
    return ; 
}

