#include "CBKing.h"
#include "CChessBoard.h"

extern CChessBoard chess_board ;

void CBKing::Draw(HDC hdc, int x, int y)
{
    Gdiplus::Graphics graphics(hdc) ;
    Gdiplus::Image img(m_imgfile_name) ;
    graphics.DrawImage(&img, x * 60, y * 60, 60, 60) ;
}

bool CBKing::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(tar_x - cur_x) ;
    int y = std::abs(tar_y - cur_y) ;
    if (x < 2 && y < 2) 
    {
        m_can_castle = false ;
        return true ;
    }
    return false ; 
}
