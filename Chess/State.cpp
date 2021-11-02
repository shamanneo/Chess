#include "State.h"

CState::CState(CChessBoard *chess_board, HWND hwnd)
{
    m_chess_board = chess_board ; 
    m_hwnd = hwnd ; 
}

bool CState::WhiteSelect(int x, int y)
{
    return false ; 
}

bool CState::WhiteMove(int x, int y)
{
    return false ; 
}

bool CState::BlackSelect(int x, int y)
{
    return false ; 
}

bool CState::BlackMove(int x, int y)
{
    return false ; 
}

CChessBoard *CState::GetChessBoard() const
{
    return m_chess_board ; 
}

HWND CState::Gethwnd() const
{
    return m_hwnd ; 
}

