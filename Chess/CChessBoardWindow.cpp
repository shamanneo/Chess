#include "CChessBoardWindow.h"

LRESULT CChessBoardWindow::ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    CChessBoardWindow *cb_wnd = reinterpret_cast<CChessBoardWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA)) ;
    return cb_wnd->ChessBoardWndProc(hwnd, message, wParam, lParam) ;

    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hwnd);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
        break;
    }
    case WM_PAINT:
    {
        OnPaint(hwnd, message, wParam, lParam) ;

        CChessBoardWindow *cb_wnd = reinterpret_cast<CChessBoardWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA)) ;
        CChessBoard *chess_board = cb_wnd->GetChessBoard() ;
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps) ;
        chess_board->SetBoard(hwnd, hdc) ;
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_LBUTTONDOWN:
    {
        static CChessGame chess_game ;
        CChessBoardWindow *cb_wnd = reinterpret_cast<CChessBoardWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA)) ;
        CChessBoard *chess_board = cb_wnd->GetChessBoard() ;
        int x = GET_X_LPARAM(lParam) / 60 ;
        int y = GET_Y_LPARAM(lParam) / 60 ;
        chess_game.Picked(hwnd, x, y) ;
        break ;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    default:
    {
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    }
    return 0;
}