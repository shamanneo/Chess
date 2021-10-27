#include "PaintChessBoard.h"
#include "Piece.h"
#include "ChessBoard.h"

CPaintChessBoard::CPaintChessBoard(HWND hwnd, CChessBoard *chessboard)
    : m_hdc(GetDC(hwnd)), m_graphics(m_hdc)
{
    m_chessboard = chessboard ; 
    m_hwnd = hwnd ; 
}

CPaintChessBoard::~CPaintChessBoard()
{
    ReleaseDC(m_hwnd, m_hdc) ; 
}

void CPaintChessBoard::DrawBoard()
{
    CPiece* piece = nullptr ; 
    Gdiplus::Image img(L"chessboard.png") ;
    m_graphics.DrawImage(&img, 0, 0, m_size * 8, m_size * 8) ;

    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            piece = m_chessboard->GetPiece(x, y) ; 
            if (piece != nullptr)
            {
                //piece->Draw(m_size, m_graphics, x, y) ; 
            }
        }
    }
}

void CPaintChessBoard::DrawSmallRect(int x, int y)
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

void CPaintChessBoard::MarkPos(int x, int y)
{
    Gdiplus::SolidBrush brush(Gdiplus::Color(100, 0, 100, 0)) ;
    m_graphics.FillRectangle(&brush, x * m_size + 1, y * m_size + 1, m_size, m_size) ;
}

void CPaintChessBoard::ErasePos(int x, int y)
{
    DrawSmallRect(x, y) ;
    CPiece *piece = m_chessboard->GetPiece(x, y) ;
    //piece->Draw(m_size, m_graphics, x, y) ;
} 