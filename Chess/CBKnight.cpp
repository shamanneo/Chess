#include "CBKnight.h"
#include "CChessBoard.h"

extern CChessBoard chess_board ;

void CBKnight::Draw(HDC hdc, int x, int y)
{
    Gdiplus::Graphics graphics(hdc) ;
    Gdiplus::Image img(m_imgfile_name) ;
    graphics.DrawImage(&img, x * 60, y * 60, 60, 60) ;
}

bool CBKnight::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(this->GetX() - tar_x) ;
    int y = std::abs(this->GetY() - tar_y) ;
    return (x * y == 2) ;
}


