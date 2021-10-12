// Chess.cpp : Defines the entry point for the application.
#include "framework.h"
#include "Chess.h"
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>
#include "CChessBoard.h"
#include "CChessGame.h"
#include <windowsx.h>

#pragma comment (lib, "Gdiplus.lib") 

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];   
WCHAR szChessBoardWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
ATOM                MyRegisterChessBoardClass(HINSTANCE hInstance) ;
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChessBoardWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

CChessBoard chess_board ;
HWND my_hwnd ;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    lstrcpy(szChessBoardWindowClass, _T("ChessBoardClass")) ; 
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    ULONG_PTR gdiplustoken ; 
    Gdiplus::GdiplusStartupInput gdiplusStartupInput ;
    Gdiplus::GdiplusStartup(&gdiplustoken, &gdiplusStartupInput, nullptr) ;
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CHESS, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);
    MyRegisterChessBoardClass(hInstance) ; 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CHESS));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    Gdiplus::GdiplusShutdown(gdiplustoken) ; 

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = 0 ; 
    wcex.lpfnWndProc    = WndProc ;
    wcex.cbClsExtra     = 0 ;
    wcex.cbWndExtra     = 0 ;
    wcex.hInstance      = hInstance ;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CHESS)) ;
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW) ;
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0) ;
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CHESS) ;
    wcex.lpszClassName  = szWindowClass ;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)) ;

    return RegisterClassExW(&wcex);
}

ATOM MyRegisterChessBoardClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = 0 ;
    wcex.lpfnWndProc = ChessBoardWndProc ;
    wcex.cbClsExtra = 0 ;
    wcex.cbWndExtra = 0 ;
    wcex.hInstance = hInstance ;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CHESS)) ;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW) ;
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 0) ;
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CHESS) ;
    wcex.lpszClassName = szChessBoardWindowClass ; 
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)) ;

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   const DWORD wsStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ;
   HWND main_hwnd = CreateWindowW(szWindowClass, szTitle, wsStyle, 0, 0, 600, 539, nullptr, nullptr, hInstance, nullptr) ;
   HWND chessboard_hwnd = CreateWindowW(szChessBoardWindowClass, szTitle, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 480, 480, main_hwnd, nullptr, hInstance, nullptr) ; 
   my_hwnd = chessboard_hwnd ; 

   if (!main_hwnd)
   {
      return FALSE;
   }

   ShowWindow(main_hwnd, nCmdShow);
   UpdateWindow(main_hwnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
                case IDM_ABOUT:
                {
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
                }
                case IDM_EXIT:
                {
                    DestroyWindow(hWnd);
                    break;
                }
                default:
                {
                    return DefWindowProc(hWnd, message, wParam, lParam);
                }
            }
            break;
        }
        case WM_PAINT :
        {
            PAINTSTRUCT ps ;
            HDC hdc = BeginPaint(hWnd, &ps);
            Gdiplus::Graphics gp(hWnd) ;
            Gdiplus::Pen pen(Gdiplus::Color(255, 65, 65, 65)) ;
            gp.DrawRectangle(&pen, 0, 0, 600, 549) ;
            EndPaint(hWnd, &ps) ; 
            break ; 
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        default:
        {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    return 0;
}

LRESULT CALLBACK ChessBoardWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps) ;
            chess_board.SetBoard(hWnd, hdc) ;
            EndPaint(hWnd, &ps);
            break;
        }
        case WM_LBUTTONDOWN:
        {
            static CChessGame chess_game ; 
            int x = GET_X_LPARAM(lParam) / 60 ;
            int y = GET_Y_LPARAM(lParam) / 60 ;
            chess_game.Picked(x, y) ; 
            break ;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        default:
        {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
