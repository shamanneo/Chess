#include "PaintChessBoard.h"
#include "Piece.h"
#include "ChessBoard.h"

CPaintChessBoard::CPaintChessBoard(HWND hwnd)
    : m_hdc(GetDC(hwnd)), m_graphics(m_hdc)
{
    m_hwnd = hwnd ; 
}

CPaintChessBoard::~CPaintChessBoard()
{
    ReleaseDC(m_hwnd, m_hdc) ; 
}

void CPaintChessBoard::DrawBoard(CChessBoard *chess_board)
{
    CPiece *piece = nullptr ; 
    Gdiplus::Image img(L"chessboard.png") ;
    m_graphics.DrawImage(&img, 0, 0, m_size * 8, m_size * 8) ;
    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            piece = chess_board->GetPiece(x, y) ; 
            if (piece != nullptr)
            {
                DrawPiece(piece, x, y) ; 
            }
        }
    }
}

void CPaintChessBoard::DrawPiece(CPiece *piece, int x, int y)
{
    piece->Draw(m_size, &m_graphics, x, y) ; 
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

void CPaintChessBoard::ErasePos(int x, int y) // modification.
{
    DrawSmallRect(x, y) ;
    /*
    CPiece *piece = m_chess_board->GetPiece(x, y) ; // 2
    piece->Draw(m_size, &m_graphics, x, y) ;
    */ // ====> Go to DrawPiece method. 
} 