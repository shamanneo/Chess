#include "Piece.h"
#include "ChessBoard.h"
#include "WKing.h"
#include "BKing.h"

CPiece::CPiece(int x, int y, CChessBoard *chess_board, HWND hwnd)
    : m_x(x), m_y(y), m_chess_board(chess_board), m_hwnd(hwnd) 
{

}

CPiece::~CPiece()
{

}

void CPiece::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    return ;
}

bool CPiece::Move(int tar_x, int tar_y)
{
    int cur_x = this->GetX() ; 
    int cur_y = this->GetY() ;
    return this->CanMove(cur_x, cur_y, tar_x, tar_y) ; 
}

bool CPiece::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    CPiece *cur = GetChessBoard()->GetPiece(cur_x, cur_y) ;
    CPiece *tar = GetChessBoard()->GetPiece(tar_x, tar_y) ;
    if (tar == nullptr)
    {
        return true ; 
    }
    return (cur->GetColor() != tar->GetColor()) ; 
}

void CPiece::SetXY(int x, int y)
{
    m_x = x ;
    m_y = y ;
}

CChessBoard *CPiece::GetChessBoard() const
{
    return m_chess_board ; 
}

HWND CPiece::Gethwnd() const
{
    return m_hwnd ; 
}

void CPiece::AfterMove(int cur_x, int cur_y, int tar_x, int tar_y, CPiece &cur_piece)
{
    CPaintChessBoard pcb(m_hwnd) ;
    pcb.DrawSmallRect(cur_x, cur_y) ;
    pcb.DrawSmallRect(tar_x, tar_y) ;
    pcb.DrawPiece(&cur_piece, tar_x, tar_y) ;
    CPiece *piece = m_chess_board->GetPiece(tar_x, tar_y) ; 
    if(dynamic_cast<CWKing *>(piece)) // Gameover. Black player win!
    {
        DialogBox(NULL, MAKEINTRESOURCE(IDD_BLACKWIN), m_hwnd, nullptr) ;    
    }
    if(dynamic_cast<CBKing *>(piece)) // Gameover. White player win!
    {
        DialogBox(NULL, MAKEINTRESOURCE(IDD_WHITEWIN), m_hwnd, nullptr) ;    
    }
    GetChessBoard()->SetPieces(cur_x, cur_y, tar_x, tar_y, cur_piece) ;
    cur_piece.SetXY(tar_x, tar_y) ;
}
