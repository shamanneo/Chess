#include "WPawn.h"
#include "ChessBoard.h"
#include "WQueen.h"

CWPawn::CWPawn(int x, int y, CChessBoard *chess_board, HWND hwnd)
    : CPiece(x, y, chess_board, hwnd), m_img(m_imgfile_name) 
{
    m_is_moved = false ; 
}

CWPawn::~CWPawn()
{

}

void CWPawn::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    graphics->DrawImage(&m_img, x * size, y * size, size, size) ;
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
    if (tar_piece != nullptr) // Attack.
    {
        if ((x == 1 && y == 1) || (x == -1 && y == 1))
        {
            if (tar_y == 0)
            {
                Promotion(cur_x, cur_y, tar_x, tar_y) ; 
                return true ; 
            }
            AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
            return true ;
        }
        return false ; 
    }
    else if (x == 0 && y == 1) // General move. 
    {
        m_is_moved = true ;
        if (tar_y == 0)
        {
            Promotion(cur_x, cur_y, tar_x, tar_y) ;
            return true ;
        }
        AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
        return true ;
    }
    else if (x == 0 && y == 2 && m_is_moved == false) // Move 2 spaces when first turn. 
    {
        CPiece *piece = GetChessBoard()->GetPiece(cur_x, cur_y - 1) ;
        if (piece != nullptr)
        {
            return false ; 
        }
        m_is_moved = true ;
        AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
        return true ;
    }
    return false ;
}

inline int CWPawn::GetColor() const
{
    return m_color ;
}

void CWPawn::Promotion(int cur_x, int cur_y, int tar_x, int tar_y) 
{
    CChessBoard *cb = GetChessBoard() ; 
    HWND hwnd = Gethwnd() ; 
    delete this ;     
    CPiece *new_piece = new CWQueen(tar_x, tar_y, cb, hwnd) ; 

    CPaintChessBoard pcb(hwnd) ;
    pcb.DrawSmallRect(cur_x, cur_y) ;
    pcb.DrawSmallRect(tar_x, tar_y) ;
    pcb.DrawPiece(new_piece, tar_x, tar_y) ;
    cb->SetPieces(cur_x, cur_y, tar_x, tar_y, *new_piece) ; 
}
