#include "WhiteTurn.h"
#include "ChessGame.h"

CWhiteTurn::CWhiteTurn(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board)
    : CState(chess_board, paint_board) 
{
    m_chess_game = chess_game ;
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
            GetPaintBoard()->ErasePos(prev->GetX(), prev->GetY()) ;
        }
        GetPaintBoard()->MarkPos(cur->GetX(), cur->GetY()) ;
        return true ;
    }
}

bool CWhiteTurn::WhiteSelect(int x, int y)
{
    CPiece *prev = m_chess_game->GetPrevPiece() ; 
    CPiece *cur = GetChessBoard()->GetPiece(x, y) ; 
    if (CanPicked(prev, cur) == true)
    {
        m_chess_game->SetState(m_chess_game->GetWhiteReadyState()) ;
        m_chess_game->SetPrevPiece(cur) ; 
    }
    return true ; 
}

bool CWhiteTurn::WhiteMove(int x, int y)
{
    return false ; 
}

bool CWhiteTurn::BlackSelect(int x, int y)
{
    return false ; 
}

bool CWhiteTurn::BlackMove(int x, int y)
{
    return false ; 
}