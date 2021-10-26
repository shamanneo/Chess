#include "FaintChessBoard.h"
#include "Piece.h"

CFaintChessBoard::CFaintChessBoard(HWND hwnd)
    : m_graphics(hwnd) 
{
    m_hwnd = hwnd ; 
    m_hdc = GetDC(hwnd) ; 
}

CFaintChessBoard::~CFaintChessBoard()
{
    ReleaseDC(m_hwnd, m_hdc) ; 
}

void CFaintChessBoard::DrawBoard()
{
    Gdiplus::Image img(L"chessboard.png") ;
    m_graphics.DrawImage(&img, 0, 0, m_size * 8, m_size * 8) ;
}

void CFaintChessBoard::DrawSmallRect(int x, int y)
{
    if ((x + y) % 2 == 0)
    {
        Gdiplus::Image img(L"white_rect.png") ;
        m_graphics.DrawImage(&img, x * m_size + 1, y * m_size + 1, m_size, m_size) ;
    }
    else
    {
        Gdiplus::Image img(L"black_rect.png") ;
        m_graphics.DrawImage(&img, x * m_size + 1, y * m_size + 1, m_size, m_size) ;
    }
}

void CFaintChessBoard::MarkPos(int x, int y)
{
    Gdiplus::SolidBrush brush(Gdiplus::Color(100, 0, 100, 0)) ;
    m_graphics.FillRectangle(&brush, x * m_size + 1, y * m_size + 1, m_size, m_size) ;
}

void CFaintChessBoard::ErasePos(int x, int y)
{
    DrawSmallRect(x, y) ;
    // CPiece* piece = GetPiece(x, y) ; 
    // piece->Draw(m_size, m_graphics, x, y) ;
} 