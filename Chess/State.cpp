#include "State.h"

CState::CState(CChessBoard *chess_board, CPaintChessBoard *paint_board)
{
    m_chess_board = chess_board ; 
    m_paint_board = paint_board ; 
}

void CState::WhiteSelect(int x, int y)
{
    return ; 
}

void CState::WhiteMove(int x, int y)
{
    return ; 
}

void CState::BlackSelect(int x, int y)
{
    return ; 
}

void CState::BlackMove(int x, int y)
{
    return ;
}

CChessBoard *CState::GetChessBoard() const
{
    return m_chess_board ; 
}

CPaintChessBoard *CState::GetPaintBoard() const
{
    return m_paint_board ; 
}