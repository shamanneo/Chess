#include "WQueen.h"
#include "ChessBoard.h"

CWQueen::CWQueen(int x, int y, CChessBoard* chess_board)
    : CPiece(x, y, chess_board), m_img(m_imgfile_name)
{

}

void CWQueen::Draw(const int size, Gdiplus::Graphics graphics, int x, int y)
{
    graphics.DrawImage(&m_img, x * size, y * size, size, size) ;
}

bool CWQueen::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = std::abs(tar_x - cur_x) ;
    int y = std::abs(tar_y - cur_y) ;
    int temp_x = cur_x ;
    int temp_y = cur_y ;
    CPiece *piece = nullptr ;
    if (x == y)
    {
        int n = x ;
        int i = 1 ;
        x = (tar_x - cur_x) / n ;
        y = (tar_y - cur_y) / n ;
        while (true)
        {
            temp_x = cur_x + (i * x) ;
            temp_y = cur_y + (i * y) ;
            if (temp_x == tar_x && temp_y == tar_y)
            {
                break ;
            }
            piece = GetChessBoard()->GetPiece(temp_x, temp_y) ;
            if (piece != nullptr)
            {
                return false ;
            }
            i++ ;
        }
        return true ;
    }
    else if (x == 0 || y == 0)
    {
        int n = (x > y) ? x : y ;
        int i = 1 ;
        x = (tar_x - cur_x) / n ;
        y = (tar_y - cur_y) / n ;
        while (true)
        {
            temp_x = cur_x + (i * x) ;
            temp_y = cur_y + (i * y) ;
            if (temp_x == tar_x && temp_y == tar_y)
            {
                break ;
            }
            piece = GetChessBoard()->GetPiece(temp_x, temp_y) ;
            if (piece != nullptr)
            {
                return false ;
            }
            i++ ;
        }
        return true ;
    }
    return false ;
}

inline int CWQueen::GetColor() const
{
    return m_color ;
}