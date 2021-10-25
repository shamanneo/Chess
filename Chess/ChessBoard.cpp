#include "framework.h"
#include "Chess.h"
#include "ChessBoard.h"
#include "Header.h"
#pragma comment (lib, "Gdiplus.lib") 

extern HWND my_hwnd ;

CChessBoard::CChessBoard()
{
    Reset() ;
}

void CChessBoard::Reset()
{
    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            m_chess_board[x][y] = nullptr ;
        }
    }
    m_chess_board[0][0] = new CBRook(0, 0) ;
    m_chess_board[1][0] = new CBKnight(1, 0) ; 
    m_chess_board[2][0] = new CBBishop(2, 0) ; 
    m_chess_board[3][0] = new CBQueen(3, 0) ;
    m_chess_board[4][0] = new CBKing(4, 0) ;
    m_chess_board[5][0] = new CBBishop(5, 0) ;
    m_chess_board[6][0] = new CBKnight(6, 0) ;
    m_chess_board[7][0] = new CBRook(7, 0) ;

    m_chess_board[0][1] = new CBPawn(0, 1) ;
    m_chess_board[1][1] = new CBPawn(1, 1) ;
    m_chess_board[2][1] = new CBPawn(2 ,1) ; 
    m_chess_board[3][1] = new CBPawn(3, 1) ; 
    m_chess_board[4][1] = new CBPawn(4, 1) ; 
    m_chess_board[5][1] = new CBPawn(5, 1) ; 
    m_chess_board[6][1] = new CBPawn(6, 1) ;
    m_chess_board[7][1] = new CBPawn(7, 1) ;

    m_chess_board[0][7] = new CWRook(0, 7) ;
    m_chess_board[1][7] = new CWKnight(1, 7) ;
    m_chess_board[2][7] = new CWBishop(2, 7) ;
    m_chess_board[3][7] = new CWQueen(3, 7) ;
    m_chess_board[4][7] = new CWKing(4, 7) ; 
    m_chess_board[5][7] = new CWBishop(5, 7) ;
    m_chess_board[6][7] = new CWKnight(6, 7) ;
    m_chess_board[7][7] = new CWRook(7, 7) ;

    m_chess_board[0][6] = new CWPawn(0, 6) ;
    m_chess_board[1][6] = new CWPawn(1, 6) ;
    m_chess_board[2][6] = new CWPawn(2, 6) ;
    m_chess_board[3][6] = new CWPawn(3, 6) ;
    m_chess_board[4][6] = new CWPawn(4, 6) ;
    m_chess_board[5][6] = new CWPawn(5, 6) ;
    m_chess_board[6][6] = new CWPawn(6, 6) ;
    m_chess_board[7][6] = new CWPawn(7, 6) ;
}

void CChessBoard::DrawBoard(HWND hWnd, HDC hdc)
{
    Gdiplus::Graphics graphics(hdc) ; 
    Gdiplus::Image img(L"chessboard.png") ; 
    graphics.DrawImage(&img, 0, 0, 480, 480) ; 
    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            if (m_chess_board[x][y] != nullptr)
            {
                m_chess_board[x][y]->Draw(hdc, x, y) ;
            }
        }
    }
}

void CChessBoard::SetPieces(int tar_x, int tar_y, int cur_x, int cur_y, CPiece &piece)
{
    HDC hdc = GetDC(my_hwnd) ;
    DrawSmallRect(hdc, cur_x, cur_y) ;
    DrawSmallRect(hdc, tar_x, tar_y) ;
    m_chess_board[cur_x][cur_y]->Draw(hdc, tar_x, tar_y) ;
    if (m_chess_board[tar_x][tar_y] == nullptr) // just move.
    {
        m_chess_board[tar_x][tar_y] = &piece ;
    }
    else // attack. 
    {
        CPiece *temp = m_chess_board[tar_x][tar_y] ;
        m_chess_board[tar_x][tar_y] = &piece ; 
        delete temp ; 
    }
    m_chess_board[cur_x][cur_y] = nullptr ;
    ReleaseDC(my_hwnd, hdc) ;
}

void CChessBoard::DrawSmallRect(HDC hdc, int x, int y) const
{
    Gdiplus::Graphics graphics(hdc) ;
    if ((x + y) % 2 == 0)
    {
        Gdiplus::Image img(L"white_rect.png") ;
        graphics.DrawImage(&img, x * 60 + 1, y * 60 + 1, 60, 60) ;
    }
    else
    {
        Gdiplus::Image img(L"black_rect.png") ;
        graphics.DrawImage(&img, x * 60 + 1, y * 60 + 1, 60, 60) ;
    }
}

void CChessBoard::DrawCurrentPos(int x, int y) const
{
    HDC hdc = GetDC(my_hwnd) ; 
    Gdiplus::Graphics graphics(hdc) ; 
    Gdiplus::SolidBrush brush(Gdiplus::Color(100, 0, 100, 0)) ; 
    graphics.FillRectangle(&brush, x * 60 + 1, y * 60 + 1, 60, 60) ; 
    ReleaseDC(my_hwnd, hdc) ; 
}

void CChessBoard::ErasePrevPos(int x, int y) const
{
    HDC hdc = GetDC(my_hwnd) ;
    Gdiplus::Graphics graphics(hdc) ;
    DrawSmallRect(hdc, x, y) ; 
    CPiece *piece = GetPiece(x, y) ; 
    piece->Draw(hdc, x, y) ; 
    ReleaseDC(my_hwnd, hdc) ;
}


