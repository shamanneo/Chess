#include "Piece.h"
#include "ChessBoard.h"

CPiece::CPiece(int x, int y, CChessBoard *chess_board, HWND hwnd)
    : m_x(x), m_y(y), m_chess_board(chess_board), m_hwnd(hwnd) 
{

}

void CPiece::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    return ;
}

bool CPiece::Move(int tar_x, int tar_y)
{
    int cur_x = this->GetX() ; 
    int cur_y = this->GetY() ;
    if (!this->CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    CPaintChessBoard pcb(m_hwnd) ;
    pcb.DrawSmallRect(cur_x, cur_y) ; 
    pcb.DrawSmallRect(tar_x, tar_y) ; 
    pcb.DrawPiece(this, tar_x, tar_y) ; 
    /*
    GetPaintBoard()->DrawSmallRect(prev->GetX(), prev->GetY());
    GetPaintBoard()->DrawSmallRect(x, y);
    GetPaintBoard()->DrawPiece(prev, x, y);
    */
    GetChessBoard()->SetPieces(this->GetX(), this->GetY(), tar_x, tar_y, *this) ;
    return true ;
}

bool CPiece::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    CPiece *cur_pos = GetChessBoard()->GetPiece(cur_x, cur_y) ;
    CPiece *tar_pos = GetChessBoard()->GetPiece(tar_x, tar_y) ;
    if (tar_pos == nullptr)
    {
        return true ; 
    }
    return (cur_pos->GetColor() != tar_pos->GetColor()) ; 
}

inline int CPiece::GetColor() const
{
    return 0 ;
}

inline int CPiece::GetX() const
{
    return m_x ;
}

inline int CPiece::GetY() const
{
    return m_y ;
}

void CPiece::SetXY(int x, int y)
{
    m_x = x ;
    m_y = y ;
}

CChessBoard *CPiece::GetChessBoard() const
{
    return m_chess_board ; 
}
