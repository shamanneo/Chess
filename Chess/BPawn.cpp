#include "BPawn.h"
#include "ChessBoard.h"
#include "BQueen.h"

CBPawn::CBPawn(int x, int y, CChessBoard *chess_board, HWND hwnd, bool forward_direction)
    : CPiece(x, y, chess_board, hwnd), m_img(m_imgfile_name)
{
    m_is_moved = false ;
    m_forward_direction = forward_direction ; 
}

CBPawn::~CBPawn()
{

}

void CBPawn::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    graphics->DrawImage(&m_img, x * size, y * size, size, size) ;
}

bool CBPawn::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    if (!CPiece::CanMove(cur_x, cur_y, tar_x, tar_y))
    {
        return false ;
    }
    int x = cur_x - tar_x ;
    int y = cur_y - tar_y ;
    CPiece *tar_piece = GetChessBoard()->GetPiece(tar_x, tar_y) ;

    if(m_forward_direction == true)
    {
        CPiece *first_piece = GetChessBoard()->GetPiece(cur_x, cur_y - 1) ;
        if(IsUpPromotion(x, y, tar_y) == true)
        {
            Promotion(cur_x, cur_y, tar_x, tar_y) ; 
            return true ;             
        }
        if(Up(x, y, tar_piece, first_piece, m_is_moved) == true)
        {
            AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
            return true ; 
        }
        return false ; 
    }
    else
    {
        CPiece *first_piece = GetChessBoard()->GetPiece(cur_x, cur_y + 1) ;
        if(IsDownPromotion(x, y, tar_y) == true)
        {
            Promotion(cur_x, cur_y, tar_x, tar_y) ; 
            return true ; 
        }
        if(Down(x, y, tar_piece, first_piece, m_is_moved) == true)
        {
            AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
            return true ; 
        }
        return false ; 
    }
}

void CBPawn::Promotion(int cur_x, int cur_y, int tar_x, int tar_y)
{
    CChessBoard* cb = GetChessBoard() ;
    HWND hwnd = Gethwnd() ;
    delete this ;
    CPiece* new_piece = new CBQueen(tar_x, tar_y, cb, hwnd) ;

    CPaintChessBoard pcb(hwnd) ;
    pcb.DrawSmallRect(cur_x, cur_y) ;
    pcb.DrawSmallRect(tar_x, tar_y) ;
    pcb.DrawPiece(new_piece, tar_x, tar_y) ;
    cb->SetPieces(cur_x, cur_y, tar_x, tar_y, *new_piece) ;
}