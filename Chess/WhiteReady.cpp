#include "WhiteReady.h"
#include "ChessGame.h"

CWhiteReady::CWhiteReady(CChessGame *chess_game, CChessBoard *chess_board)
{
    m_chess_game = chess_game ;
    m_chess_board = chess_board ;
}

void CWhiteReady::WhiteSelect(int x, int y)
{
    return ; 
}

void CWhiteReady::WhiteMove(int x, int y)
{
    CPiece *prev= m_chess_game->GetPrevPiece() ; 
    CPiece *cur = m_chess_board->GetPiece(x, y);
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

