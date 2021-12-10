#include "WhiteReady.h"
#include "ChessGame.h"

extern CChessBoardWindow *lcb_wnd ;

CWhiteReady::CWhiteReady(CChessGame *chess_game, CChessBoard *chess_board, HWND hwnd)
    : CState(chess_board, hwnd)
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
        return true ; 
    }
    else if ((cur != nullptr) && (prev->GetColor() == 1) && (cur->GetColor() == 1))
    {
        m_chess_game->SetState(m_chess_game->GetWhiteTurnState()) ; 
        m_chess_game->WhiteSelect(x, y) ; 
        m_chess_game->SetPrevPiece(cur) ;
    }
    else if (prev->Move(x, y))
    {
        m_chess_game->SetState(m_chess_game->GetBlackTurnState()) ; 
        m_chess_game->SetPrevPiece(nullptr) ;
        lcb_wnd->Save() ; 
    }
    return true ;
}

bool CWhiteReady::BlackSelect(int x, int y)
{
    return false ; 
}

bool CWhiteReady::BlackMove(int x, int y)
{
    return false ; 
}

