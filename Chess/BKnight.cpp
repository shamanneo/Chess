#include "BKnight.h"
#include "ChessBoard.h"

CBKnight::CBKnight(int x, int y, CChessBoard *chess_board, HWND hwnd)
    : CPiece(x, y, chess_board, hwnd), m_img(m_imgfile_name)
{

}

CBKnight::~CBKnight()
{

}

void CBKnight::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    graphics->DrawImage(&m_img, x * size, y * size, size, size) ;
}

bool CBKnight::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(this->GetX() - tar_x) ;
    int y = std::abs(this->GetY() - tar_y) ;
    if (x * y == 2)
    {
        AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
        return true ; 
    }
    return false ; 
}

inline int CBKnight::GetColor() const
{
    return m_color ;
}


