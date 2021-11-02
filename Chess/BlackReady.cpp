#include "BlackReady.h"
#include "ChessGame.h"

CBlackReady::CBlackReady(CChessGame *chess_game, CChessBoard *chess_board, HWND hwnd)
    : CState(chess_board, hwnd)
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
        return true ;
    }
    else if ((cur != nullptr) && (prev->GetColor() == 0) && (cur->GetColor() == 0))
    {
        m_chess_game->SetState(m_chess_game->GetBlackTurnState()) ;
        m_chess_game->BlackSelect(x, y) ; 
        m_chess_game->SetPrevPiece(cur) ;
    }
    else if (prev->Move(x, y))
    {
        m_chess_game->SetState(m_chess_game->GetWhiteTurnState()) ;
        m_chess_game->SetPrevPiece(nullptr) ; 
    }
    return true ;
}