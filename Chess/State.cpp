#include "State.h"

CState::CState(CChessBoard *chess_board, CPaintChessBoard *paint_board)
{
    m_chess_board = chess_board ; 
    m_paint_board = paint_board ; 
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

CPaintChessBoard *CState::GetPaintBoard() const
{
    return m_paint_board ; 
}