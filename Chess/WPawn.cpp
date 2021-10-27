#include "WPawn.h"
#include "ChessBoard.h"

CWPawn::CWPawn(int x, int y, CChessBoard *chess_board)
    : CPiece(x, y, chess_board), m_img(m_imgfile_name) 
{
    m_is_moved = false ; 
}

void CWPawn::Draw(const int size, Gdiplus::Graphics graphics, int x, int y)
{
    graphics.DrawImage(&m_img, x * size, y * size, size, size) ;
}

bool CWPawn::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = cur_x - tar_x ;
    int y = cur_y - tar_y ;
    CPiece *tar_piece = GetChessBoard()->GetPiece(tar_x, tar_y) ;
    if (tar_piece != nullptr)
    {
        if ((x == 1 && y == 1) || (x == -1 && y == 1))
        {
            return true ;
        }
        return false ; 
    }
    else if (x == 0 && y == 1)
    {
        m_is_moved = true ;
        return true ;
    }
    else if (x == 0 && y == 2 && m_is_moved == false)
    {
        CPiece *piece = GetChessBoard()->GetPiece(cur_x, cur_y - 1) ;
        if (piece != nullptr)
        {
            return false ; 
        }
        m_is_moved = true ;
        return true ;
    }
    return false ;
}

inline int CWPawn::GetColor() const
{
    return m_color ;
}
