#include "CWKing.h"
#include "CWRook.h"
#include "CChessBoard.h"

extern CChessBoard chess_board ;

void CWKing::Draw(HDC hdc, int x, int y)
{
    Gdiplus::Graphics graphics(hdc) ;
    Gdiplus::Image img(m_imgfile_name) ;
    graphics.DrawImage(&img, x * 60, y * 60, 60, 60) ;
}

bool CWKing::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
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
    if ((tar_x - cur_x == 2) && (tar_y - cur_y == 0)) // KingSide Castling.
    {
        return KingSideCastling() ; 
    }
    else if ((tar_x - cur_x == -2) && (tar_y - cur_y == 0)) // QueenSide Castling.
    {
        return QueenSideCastling() ;
    }
    return false ; 
}

bool CWKing::KingSideCastling()
{
    CPiece *piece = chess_board.GetPiece(7, 7) ; 
    CWRook *king_side_rook = dynamic_cast<CWRook *>(piece) ; 
    if (!m_can_castle || king_side_rook->CanCastling() == false)
    {
        return false ;
    }
    CPiece *f1 = chess_board.GetPiece(5, 7) ;
    CPiece *g1 = chess_board.GetPiece(6, 7) ;
    if (f1 == nullptr && g1 == nullptr)
    {
        if (IsCheckMated())
        {
            return king_side_rook->Move(5, 7) ; 
        }
    }
    return false ;
}
bool CWKing::QueenSideCastling()
{
    CPiece *piece = chess_board.GetPiece(0, 7) ;
    CWRook *queen_side_rook = dynamic_cast<CWRook *>(piece) ;
    if (!m_can_castle || queen_side_rook->CanCastling() == false)
    {
        return false ;
    }
    CPiece *b1 = chess_board.GetPiece(1, 7) ;
    CPiece *c1 = chess_board.GetPiece(2, 7) ;
    CPiece *d1 = chess_board.GetPiece(3, 7) ;
    if ((b1 == nullptr) && (c1 == nullptr) && (d1 == nullptr))
    {
        if (IsCheckMated())
        {
            return queen_side_rook->Move(3, 7) ;
        }
    }
    return false ;
}
bool CWKing::IsCheckMated()
{
    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            CPiece *piece = chess_board.GetPiece(x, y) ;
            if (piece != nullptr)
            {
                if (piece->CanMove(piece->GetX(), piece->GetY(), this->GetX(), this->GetY()))
                {
                    return false ;
                }
            }
        }
    }
    return true ; 
}