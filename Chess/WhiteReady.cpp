#include "WhiteReady.h"
#include "ChessGame.h"

CWhiteReady::CWhiteReady(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board)
    : CState(chess_board, paint_board)
{
    m_chess_game = chess_game;
}

void CWhiteReady::WhiteSelect(int x, int y)
{
    return ; 
}

void CWhiteReady::WhiteMove(int x, int y)
{
    CPiece *prev= m_chess_game->GetPrevPiece() ; 
    CPiece *cur = GetChessBoard()->GetPiece(x, y);
    if (prev == cur)
    {
        return ;
    }
    else if ((cur != nullptr) && (prev->GetColor() == 1) && (cur->GetColor() == 1))
    {
        m_chess_game->SetState(m_chess_game->GetWhiteTurnState()) ; 
    }
    else if (prev->Move(x, y))
    {
        GetPaintBoard()->DrawSmallRect(prev->GetX(), prev->GetY()) ; 
        GetPaintBoard()->DrawSmallRect(x, y) ; 
        GetPaintBoard()->DrawPiece(prev, x, y) ;
        m_chess_game->SetState(m_chess_game->GetBlackTurnState()) ; 
    }
}

void CWhiteReady::BlackSelect(int x, int y)
{
    return ; 
}

void CWhiteReady::BlackMove(int x, int y)
{
    return ;
}

