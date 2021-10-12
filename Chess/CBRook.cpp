#include "CBRook.h"
#include "CChessBoard.h"

extern CChessBoard chess_board ;

void CBRook::Draw(HDC hdc, int x, int y) 
{
    Gdiplus::Graphics graphics(hdc) ;
    Gdiplus::Image img(m_imgfile_name) ;
    graphics.DrawImage(&img, x * 60, y * 60, 60, 60) ;
}

bool CBRook::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(tar_x - cur_x) ;
    int y = std::abs(tar_y - cur_y) ;
    int temp_x = cur_x ;
    int temp_y = cur_y ;
    if (x != 0 && y != 0)
    {
        return false ; 
    }
    int n = (x > y) ? x : y ; 
    int i = 1 ;
    x = (tar_x - cur_x) / n ;
    y = (tar_y - cur_y) / n ;
    CPiece *piece = nullptr ;
    while (true)
    {
        temp_x = cur_x + (i * x) ;
        temp_y = cur_y + (i * y) ;
        if (temp_x == tar_x && temp_y == tar_y)
        {
            break ;
        }
        piece = chess_board.GetPiece(temp_x, temp_y) ;
        if (piece != nullptr)
        {
            return false ;
        }
        i++ ;
    }
    m_can_castle = false ;
    return true ; 
}

