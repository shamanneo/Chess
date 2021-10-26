#include "ChessBoardWindow.h"


CChessBoardWindow::CChessBoardWindow()
{
    m_cb = new CChessBoard ;
}

LRESULT CChessBoardWindow::ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_PAINT:
        {
            OnPaint(hwnd) ; 
            break;
        }
        case WM_LBUTTONDOWN:
        {
            OnLButtonDown(lParam) ; 
            break ;
        }
        case WM_DESTROY:
        {
            OnDestory() ; 
            break;
        }
        default:
        {
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
    return 0 ;
}

void CChessBoardWindow::OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps) ;
    m_cb->DrawBoard(hwnd, hdc) ;
    EndPaint(hwnd, &ps);
}

void CChessBoardWindow::OnLButtonDown(LPARAM lParam)
{
    static CChessGame chess_game ;
    int x = GET_X_LPARAM(lParam) / 60 ;
    int y = GET_Y_LPARAM(lParam) / 60 ;
    chess_game.Picked(x, y) ;
}

void CChessBoardWindow::OnDestory()
{
    PostQuitMessage(0);
}