#include "CBKing.h"
#include "CBRook.h"
#include "CChessBoard.h"

extern CChessBoard chess_board ;

void CBKing::Draw(HDC hdc, int x, int y)
{
    Gdiplus::Graphics graphics(hdc) ;
    Gdiplus::Image img(m_imgfile_name) ;
    graphics.DrawImage(&img, x * 60, y * 60, 60, 60) ;
}

bool CBKing::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
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

bool CBKing::KingSideCastling()
{
    CPiece *piece = chess_board.GetPiece(7, 0) ;
    CBRook *king_side_rook = dynamic_cast<CBRook *>(piece) ;
    if (!m_can_castle || king_side_rook->CanCastling() == false)
    {
        return false ;
    }
    CPiece *f8 = chess_board.GetPiece(5, 0) ;
    CPiece *g8 = chess_board.GetPiece(6, 0) ;
    if (f8 == nullptr && g8 == nullptr)
    {
        if (IsCheckMated())
        {
            return king_side_rook->Move(5, 0) ;
        }
    }
    return false ;
}
bool CBKing::QueenSideCastling()
{
    CPiece *piece = chess_board.GetPiece(0, 0) ;
    CBRook *queen_side_rook = dynamic_cast<CBRook *>(piece) ;
    if (!m_can_castle || queen_side_rook->CanCastling() == false)
    {
        return false ;
    }
    CPiece *b1 = chess_board.GetPiece(1, 0) ;
    CPiece *c1 = chess_board.GetPiece(2, 0) ;
    CPiece *d1 = chess_board.GetPiece(3, 0) ;
    if ((b1 == nullptr) && (c1 == nullptr) && (d1 == nullptr))
    {
        if (IsCheckMated())
        {
            return queen_side_rook->Move(3, 0) ;
        }
    }
    return false ;
}
bool CBKing::IsCheckMated()
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
