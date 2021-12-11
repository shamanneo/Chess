#include "MainWindow.h"

extern CChessBoardWindow *lcb_wnd ;

LRESULT CALLBACK CMainWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND:
        {
            OnComamnd(hwnd, message, wParam, lParam) ;
            break ;
        }
        case WM_PAINT:
        {
            OnPaint(hwnd) ; 
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

void CMainWindow::OnComamnd(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId = LOWORD(wParam) ;
    switch (wmId)
    {
        case IDM_EXIT:
        {
            DestroyWindow(hwnd) ;
            break ;
        }
    }
}

void CMainWindow::OnPaint(HWND hwnd)
{
    //lcb_wnd->ChessBoardWndProc(hwnd, WM_PAINT, 0, 0) ;
}

void CMainWindow::OnDestory()
{
    PostQuitMessage(0) ;
}