#include "BlackTurn.h"
#include "ChessGame.h"

CBlackTurn::CBlackTurn(CChessGame *chess_game, CChessBoard *chess_board, HWND hwnd)
    : CState(chess_board, hwnd) 
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
        CPaintChessBoard pcb(Gethwnd()) ; 
        if (prev != nullptr)
        {
            pcb.ErasePos(prev->GetX(), prev->GetY()) ;
            pcb.DrawPiece(prev, prev->GetX(), prev->GetY()) ;
        }
        pcb.MarkPos(cur->GetX(), cur->GetY()) ;
        return true ;
    }
}

bool CBlackTurn::WhiteSelect(int x, int y)
{
    return false ; 
}

bool CBlackTurn::WhiteMove(int x, int y)
{
    return false ; 
}

bool CBlackTurn::BlackSelect(int x, int y)
{
    CPiece *prev = m_chess_game->GetPrevPiece() ;
    CPiece *cur = GetChessBoard()->GetPiece(x, y) ;
    if (CanPicked(prev, cur) == true)
    {
        m_chess_game->SetState(m_chess_game->GetBlackReadyState()) ;
        m_chess_game->SetPrevPiece(cur) ;
    }
    return true ;
}

bool CBlackTurn::BlackMove(int x, int y)
{
    return false ; 
}

