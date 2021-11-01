#include "WhiteReady.h"
#include "ChessGame.h"

CWhiteReady::CWhiteReady(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board)
    : CState(chess_board, paint_board)
{
    m_chess_game = chess_game;
}

bool CWhiteReady::WhiteSelect(int x, int y)
{
    return false ; 
}

bool CWhiteReady::WhiteMove(int x, int y)
{
    CPiece *prev= m_chess_game->GetPrevPiece() ; 
    CPiece *cur = GetChessBoard()->GetPiece(x, y);
    if (prev == cur)
    {
        return false ; 
    }
    else if ((cur != nullptr) && (prev->GetColor() == 1) && (cur->GetColor() == 1))
    {
        m_chess_game->SetState(m_chess_game->GetWhiteTurnState()) ; 
        return m_chess_game->WhiteSelect(x, y) ; 
    }
    else if (prev->Move(x, y))
    {
        GetPaintBoard()->DrawSmallRect(prev->GetX(), prev->GetY()) ; 
        GetPaintBoard()->DrawSmallRect(x, y) ; 
        GetPaintBoard()->DrawPiece(prev, x, y) ;
        m_chess_game->SetState(m_chess_game->GetBlackTurnState()) ; 
        return true ; 
    }
}

bool CWhiteReady::BlackSelect(int x, int y)
{
    return false ; 
}

bool CWhiteReady::BlackMove(int x, int y)
{
    return false ; 
}

