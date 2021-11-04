#include "WKing.h"
#include "WRook.h"
#include "ChessBoard.h"

CWKing::CWKing(int x, int y, CChessBoard *chess_board, HWND hwnd)
    : CPiece(x, y, chess_board, hwnd), m_img(m_imgfile_name)
{
    m_can_castle = true;
}

void CWKing::Draw(const int size, Gdiplus::Graphics *graphics, int x, int y)
{
    graphics->DrawImage(&m_img, x * size, y * size, size, size);
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
        AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
        return true ;
    }
    if ((tar_x - cur_x == 2) && (tar_y - cur_y == 0)) // KingSide Castling.
    {
        if (KingSideCastling() == true)
        {
            AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
            return true ; 
        }
    }
    else if ((tar_x - cur_x == -2) && (tar_y - cur_y == 0)) // QueenSide Castling.
    {
        if (QueenSideCastling() == true)
        {
            AfterMove(cur_x, cur_y, tar_x, tar_y, *this) ;
            return true ;
        }
    }
    return false ; 
}

inline int CWKing::GetColor() const
{
    return m_color ;
}

bool CWKing::KingSideCastling()
{
    CPiece *piece = GetChessBoard()->GetPiece(7, 7) ;
    CWRook *king_side_rook = dynamic_cast<CWRook *>(piece) ; 
    if (!m_can_castle || king_side_rook->CanCastling() == false)
    {
        return false ;
    }
    CPiece *f1 = GetChessBoard()->GetPiece(5, 7) ;
    CPiece *g1 = GetChessBoard()->GetPiece(6, 7) ;
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
    CPiece *piece = GetChessBoard()->GetPiece(0, 7) ;
    CWRook *queen_side_rook = dynamic_cast<CWRook *>(piece) ;
    if (!m_can_castle || queen_side_rook->CanCastling() == false)
    {
        return false ;
    }
    CPiece *b1 = GetChessBoard()->GetPiece(1, 7) ;
    CPiece *c1 = GetChessBoard()->GetPiece(2, 7) ;
    CPiece *d1 = GetChessBoard()->GetPiece(3, 7) ;
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
            CPiece *piece = GetChessBoard()->GetPiece(x, y) ;
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