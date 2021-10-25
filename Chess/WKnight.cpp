#include "WKnight.h"
#include "ChessBoard.h"

extern CChessBoard chess_board ;

void CWKnight::Draw(HDC hdc, int x, int y) 
{
    Gdiplus::Graphics graphics(hdc) ;
    Gdiplus::Image img(m_imgfile_name) ;
    graphics.DrawImage(&img, x * 60, y * 60, 60, 60) ;
}

bool CWKnight::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(this->GetX() - tar_x) ;
    int y = std::abs(this->GetY() - tar_y) ;
    CPiece *tar_piece = chess_board.GetPiece(tar_x, tar_y) ;
    if (tar_piece != nullptr && x * y == 2)
    {
        return true ;
    }
    return (x * y == 2) ; 
}
