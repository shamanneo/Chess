#include "Chess.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma comment (lib, "Gdiplus.lib") 

#define MAX_LOADSTRING 100

HINSTANCE hInst ;                                // current instance
WCHAR szTitle[MAX_LOADSTRING] ;                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING] ;   
WCHAR szChessBoardWindowClass[MAX_LOADSTRING] ;

ATOM                MyRegisterClass(HINSTANCE hInstance) ;
ATOM                MyRegisterChessBoardClass(HINSTANCE hInstance) ;
BOOL                InitInstance(HINSTANCE, int) ;
LRESULT CALLBACK    MainWndProc(HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK    ChessBoardWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 

CChessBoardWindow *lcb_wnd ; 

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    lstrcpy(szChessBoardWindowClass, _T("ChessBoardClass")) ; 
    UNREFERENCED_PARAMETER(hPrevInstance) ;
    UNREFERENCED_PARAMETER(lpCmdLine) ;

    ULONG_PTR gdiplustoken ; 
    Gdiplus::GdiplusStartupInput gdiplusStartupInput ;
    Gdiplus::GdiplusStartup(&gdiplustoken, &gdiplusStartupInput, nullptr) ;
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING) ;
    LoadStringW(hInstance, IDC_CHESS, szWindowClass, MAX_LOADSTRING) ;

    MyRegisterClass(hInstance) ;
    MyRegisterChessBoardClass(hInstance) ; 

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE ;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CHESS)) ;
    MSG msg ;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg) ;
            DispatchMessage(&msg) ;
        }
    }
    delete lcb_wnd ; 
    _CrtDumpMemoryLeaks() ;
    Gdiplus::GdiplusShutdown(gdiplustoken) ; 
    return (int) msg.wParam ;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex ;

    wcex.cbSize = sizeof(WNDCLASSEX) ;
    wcex.style = 0 ; 
    wcex.lpfnWndProc    = MainWndProc ;
    wcex.cbClsExtra     = 0 ;
    wcex.cbWndExtra     = 0 ;
    wcex.hInstance      = hInstance ;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CHESS)) ;
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW) ;
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0) ;
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CHESS) ;
    wcex.lpszClassName  = szWindowClass ;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)) ;

    return RegisterClassExW(&wcex) ;
}

ATOM MyRegisterChessBoardClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex ;

    wcex.cbSize = sizeof(WNDCLASSEX) ;
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

    return RegisterClassExW(&wcex) ;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance ;
    const DWORD wsStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ; 
    HWND main_hwnd = CreateWindowW(szWindowClass, szTitle, wsStyle, 0, 0, 496, 590, nullptr, nullptr, hInstance, nullptr) ;  
    HWND chess_board_hwnd = CreateWindowW(szChessBoardWindowClass, szTitle, WS_CHILD | WS_VISIBLE , 0, 0, 496, 590, main_hwnd, nullptr, hInstance, nullptr) ; 
    HWND reset_button_hwnd = CreateWindowW(_T("Button"), _T("Reset"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 10, 490, 100, 30, chess_board_hwnd, HMENU(IDC_RESET), hInstance, nullptr) ; 
    HWND undo_button_hwnd = CreateWindowW(_T("Button"), _T("Undo"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 130, 490, 100, 30, chess_board_hwnd, HMENU(IDC_UNDO), hInstance, nullptr) ; 
    HWND change_button_hwnd = CreateWindowW(_T("Button"), _T("Change"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 250, 490, 100, 30, chess_board_hwnd, HMENU(IDC_CHANGE), hInstance, nullptr) ; 
    CChessBoardWindow *cb_wnd = new CChessBoardWindow(chess_board_hwnd) ;
    lcb_wnd = cb_wnd ;
    ShowWindow(main_hwnd, nCmdShow) ;
    UpdateWindow(main_hwnd) ;
    return TRUE ;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    CMainWindow main_wnd ; 
    return main_wnd.WndProc(hwnd, message, wParam, lParam) ; 
}

LRESULT CALLBACK ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return lcb_wnd->ChessBoardWndProc(hwnd, message, wParam, lParam) ; 
}


