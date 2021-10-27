#include "WKnight.h"
#include "ChessBoard.h"

CWKnight::CWKnight(int x, int y, CChessBoard *chess_board)
    : CPiece(x, y, chess_board), m_img(m_imgfile_name)
{
    
}

void CWKnight::Draw(const int size, Gdiplus::Graphics graphics, int x, int y)
{
    graphics.DrawImage(&m_img, x * size, y * size, size, size) ;
}

bool CWKnight::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(this->GetX() - tar_x) ;
    int y = std::abs(this->GetY() - tar_y) ;
    return (x * y == 2) ; 
}

inline int CWKnight::GetColor() const
{
    return m_color ;
}