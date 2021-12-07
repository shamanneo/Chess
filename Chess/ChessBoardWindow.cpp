#include "ChessBoardWindow.h"
#include "resource.h"

extern CChessBoardWindow *lcb_wnd ;

CChessBoardWindow::CChessBoardWindow(HWND hwnd)
{
    m_cb = new CChessBoard(hwnd) ; 
    m_cg = new CChessGame(m_cb, hwnd) ;
}

CChessBoardWindow::~CChessBoardWindow()
{
    delete m_cb ; 
    delete m_cg ; 
}

LRESULT CChessBoardWindow::ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND :
        {
            OnCommand(hwnd, wParam) ;
            break ; 
        }
        case WM_PAINT :
        {
            OnPaint(hwnd) ; 
            break ;
        }
        case WM_LBUTTONDOWN :
        {
            OnLButtonDown(hwnd, lParam) ; 
            break ;
        }
        case WM_DESTROY :
        {
            OnDestory() ; 
            break ;
        }
        default :
        {
            return DefWindowProc(hwnd, message, wParam, lParam) ;
        }
    }
    return 0 ;
}

void CChessBoardWindow::Reset(HWND hwnd)
{
    delete this ; 
    CChessBoardWindow *cb_wnd = new CChessBoardWindow(hwnd) ;
    lcb_wnd = cb_wnd ; 
    InvalidateRect(hwnd, nullptr, TRUE) ; 
    UpdateWindow(hwnd) ; 
}

void CChessBoardWindow::Undo(HWND hwnd) 
{


}

void CChessBoardWindow::OnCommand(HWND hwnd, WPARAM wParam)
{
    int wmId = LOWORD(wParam) ;
    switch (wmId)
    {
        case IDC_RESET : // Reset Button Down. 
        {
            Reset(hwnd) ; 
            break ;
        }
        case IDC_UNDO : // Reset Button Down. 
        {
            Undo(hwnd) ;
            break ;
        }
    }
}

void CChessBoardWindow::OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps) ;
    CPaintChessBoard pcb(hwnd) ;
    pcb.DrawBoard(m_cb) ; 
    EndPaint(hwnd, &ps) ;
}

void CChessBoardWindow::OnLButtonDown(HWND hwnd, LPARAM lParam)
{
    int x = GET_X_LPARAM(lParam) / 60 ;
    int y = GET_Y_LPARAM(lParam) / 60 ;
    if (x > 7 || y > 7)
    {
        return ; 
    }
    m_cg->GameState(x, y) ;
}

void CChessBoardWindow::OnDestory()
{
    PostQuitMessage(0) ;
}