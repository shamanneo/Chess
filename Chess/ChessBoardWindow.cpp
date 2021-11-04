#include "ChessBoardWindow.h"

CChessBoardWindow::CChessBoardWindow(HWND hwnd)
{
    m_cb = new CChessBoard(hwnd) ; 
}

CChessBoardWindow::~CChessBoardWindow()
{
    delete m_cb ; 
}

LRESULT CChessBoardWindow::ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_PAINT:
        {
            OnPaint(hwnd) ; 
            break ;
        }
        case WM_LBUTTONDOWN:
        {
            OnLButtonDown(hwnd, lParam) ; 
            break ;
        }
        case WM_DESTROY:
        {
            OnDestory() ; 
            break ;
        }
        default:
        {
            return DefWindowProc(hwnd, message, wParam, lParam) ;
        }
    }
    return 0 ;
}

void CChessBoardWindow::OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps) ;
    CPaintChessBoard pcb(hwnd) ;
    pcb.DrawBoard(m_cb) ; 
    EndPaint(hwnd, &ps);
}

void CChessBoardWindow::OnLButtonDown(HWND hwnd, LPARAM lParam)
{
    static CChessGame chess_game(m_cb, hwnd) ;
    int x = GET_X_LPARAM(lParam) / 60 ;
    int y = GET_Y_LPARAM(lParam) / 60 ;
    chess_game.GameState(x, y) ;
}

void CChessBoardWindow::OnDestory()
{
    PostQuitMessage(0);
}