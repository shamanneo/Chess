#include "WhiteTurn.h"
#include "ChessGame.h"

CWhiteTurn::CWhiteTurn(CChessGame *chess_game, CChessBoard *chess_board)
{
    m_chess_game = chess_game ;
    m_chess_board = chess_board ; 
}

bool CWhiteTurn::CanPicked(CPiece *prev, CPiece *cur)
{
    if (prev == cur)
    {
        return false ;
    }
    else if (cur != nullptr && cur->GetColor() == 0) // is black? 
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

void CWhiteTurn::WhiteSelect(int x, int y)
{
    CPiece *prev = m_chess_game->GetPrevPiece() ; 
    CPiece *cur = m_chess_board->GetPiece(x, y) ; 
    if (CanPicked(prev, cur) == true)
    {
        m_chess_game->SetState(m_chess_game->GetWhiteReadyState()) ;
    }
}

void CWhiteTurn::WhiteMove(int x, int y)
{
    return ; 
}

void CWhiteTurn::BlackSelect(int x, int y)
{
    return ;
}

void CWhiteTurn::BlackMove(int x, int y)
{
    return ; 
}