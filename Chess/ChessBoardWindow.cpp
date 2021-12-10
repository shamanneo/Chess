#include "ChessBoardWindow.h"
#include "resource.h"

extern CChessBoardWindow *lcb_wnd ;

CChessBoardWindow::CChessBoardWindow(HWND hwnd, bool is_white)
{
    m_cb = new CChessBoard(hwnd, is_white) ; 
    m_cg = new CChessGame(m_cb, hwnd) ;
    Save() ; 
    m_is_white_player = true ; 
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

void CChessBoardWindow::Save()
{
    std::shared_ptr<int> pieces(new int[64], std::default_delete<int []>()) ; 
    for(int x = 0 ; x < 8 ; x++)
    {
        for(int y = 0 ; y < 8 ; y++)
        {
            CPiece *piece = m_cb->GetPiece(x, y) ; 
            if(piece != nullptr)
            {
                *(pieces.get() + y * 8 + x) = piece->GetID() ; 
            }
        }
    }
    m_arr_stack.push(pieces) ; 
}

void CChessBoardWindow::Reset(HWND hwnd, bool main_color)
{
    delete this ; 
    CChessBoardWindow *cb_wnd = new CChessBoardWindow(hwnd, main_color) ;
    lcb_wnd = cb_wnd ; 
    InvalidateRect(hwnd, nullptr, TRUE) ; 
    UpdateWindow(hwnd) ; 
}

void CChessBoardWindow::Undo(HWND hwnd) 
{
    size_t count = m_arr_stack.size() ; 
    if(count == 1)
    {
        return ;
    }
    else if((count % 2) == 0)
    {
        m_cg->SetState(m_cg->GetWhiteTurnState()) ; 
    }
    else if((count % 2) == 1)
    {
        m_cg->SetState(m_cg->GetBlackTurnState()) ; 
    }
    m_cg->SetPrevPiece(nullptr) ; 
    m_arr_stack.pop() ; 
    int *arr = m_arr_stack.top().get() ; 
    delete m_cb ; 
    m_cb = new CChessBoard ; 
    m_cb->CopyArrToBoard(arr, hwnd) ; 
    InvalidateRect(hwnd, nullptr, TRUE) ; 
    UpdateWindow(hwnd) ; 
}

void CChessBoardWindow::Change(HWND hwnd) 
{
    if(m_is_white_player)
    {
        m_cg->SetState(m_cg->GetWhiteTurnState()) ; 
        m_is_white_player = false ;
    }
    else
    {
        m_cg->SetState(m_cg->GetBlackTurnState()) ; 
        m_is_white_player = true ;
    }
    Reset(hwnd, m_is_white_player) ; 
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
        case IDC_CHANGE : // Change Button Down.
        {
            Change(hwnd) ;
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