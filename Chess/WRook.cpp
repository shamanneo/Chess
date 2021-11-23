#include "WRook.h"
#include "ChessBoard.h"

CWRook::CWRook(int x, int y, CChessBoard *chess_board, HWND hwnd)
    : CPiece(x, y, chess_board, hwnd), m_img(m_imgfile_name)
{
    m_can_castle = true ;
}

CWRook::~CWRook()
{

}

void CWRook::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    graphics->DrawImage(&m_img, x * size, y * size, size, size) ;
}

bool CWRook::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
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
        piece = GetChessBoard()->GetPiece(temp_x, temp_y) ;
        if (piece != nullptr)
        {
            return false ;
        }
        i++ ;
    }
    m_can_castle = false ; 
    AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
    return true ;
}

bool CWRook::CanCastling() const
{
    return m_can_castle ;
}