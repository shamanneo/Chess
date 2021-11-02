#include "MainWindow.h"

extern HINSTANCE hInst ;
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM) ;

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
        case IDM_ABOUT:
        {
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About) ;
            break ;
        }
        case IDM_EXIT:
        {
            DestroyWindow(hwnd) ;
            break ;
        }
    }
}

void CMainWindow::OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps ;
    HDC hdc = BeginPaint(hwnd, &ps) ;
    Gdiplus::Graphics gp(hwnd) ;
    Gdiplus::Pen pen(Gdiplus::Color(255, 65, 65, 65)) ;
    gp.DrawRectangle(&pen, 0, 0, 600, 549) ;
    EndPaint(hwnd, &ps) ;
}

void CMainWindow::OnDestory()
{
    PostQuitMessage(0) ;
}