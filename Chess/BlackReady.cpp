#include "BlackReady.h"
#include "ChessGame.h"

CBlackReady::CBlackReady(CChessGame *chess_game, CChessBoard *chess_board, CPaintChessBoard *paint_board)
    : CState(chess_board, paint_board)
{
    m_chess_game = chess_game ; 
}

bool CBlackReady::WhiteSelect(int x, int y)
{
    return false ; 
}

bool CBlackReady::WhiteMove(int x, int y)
{
    return false ;
}

bool CBlackReady::BlackSelect(int x, int y)
{
    return false ; 
}

bool CBlackReady::BlackMove(int x, int y)
{
    CPiece *prev = m_chess_game->GetPrevPiece() ;
    CPiece *cur = GetChessBoard()->GetPiece(x, y) ;
    if (prev == cur)
    {
        return false ;
    }
    else if ((cur != nullptr) && (prev->GetColor() == 1) && (cur->GetColor() == 1))
    {
        m_chess_game->SetState(m_chess_game->GetBlackTurnState()) ;
        return m_chess_game->BlackSelect(x, y) ; 
    }
    else if (prev->Move(x, y))
    {
        GetPaintBoard()->DrawSmallRect(prev->GetX(), prev->GetY()) ;
        GetPaintBoard()->DrawSmallRect(x, y) ;
        GetPaintBoard()->DrawPiece(prev, x, y) ;
        m_chess_game->SetState(m_chess_game->GetBlackReadyState()) ;
        return true ; 
    }
}