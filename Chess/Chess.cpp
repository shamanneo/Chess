#include "Chess.h"
#pragma comment (lib, "Gdiplus.lib") 

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst ;                                // current instance
WCHAR szTitle[MAX_LOADSTRING] ;                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING] ;   
WCHAR szChessBoardWindowClass[MAX_LOADSTRING] ;

ATOM                MyRegisterClass(HINSTANCE hInstance) ;
ATOM                MyRegisterChessBoardClass(HINSTANCE hInstance) ;
BOOL                InitInstance(HINSTANCE, int) ;
LRESULT CALLBACK    MainWndProc(HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK    ChessBoardWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 

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

    MyRegisterClass(hInstance);
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
   HWND main_hwnd = CreateWindowW(szWindowClass, szTitle, wsStyle, 0, 0, 496, 539, nullptr, nullptr, hInstance, nullptr) ;
   HWND chessboard_hwnd = CreateWindowW(szChessBoardWindowClass, szTitle, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 480, 480, main_hwnd, nullptr, hInstance, nullptr) ; 
   CChessBoardWindow *cb_wnd = new CChessBoardWindow(chessboard_hwnd) ; 
   SetWindowLongPtr(chessboard_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(cb_wnd)) ; 

   ShowWindow(main_hwnd, nCmdShow) ;
   UpdateWindow(main_hwnd) ;

   return TRUE;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    CMainWindow main_wnd ; 
    return main_wnd.WndProc(hWnd, message, wParam, lParam) ; 
}

LRESULT CALLBACK ChessBoardWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    CChessBoardWindow *cb_wnd = reinterpret_cast<CChessBoardWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA)) ;
    return cb_wnd->ChessBoardWndProc(hwnd, message, wParam, lParam) ; 
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
        case WM_INITDIALOG:
        {
            return (INT_PTR)TRUE ;
        }
        case WM_COMMAND:
        {
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, LOWORD(wParam)) ;
                return (INT_PTR)TRUE ;
            }
            break ;
        }
    }
    return (INT_PTR)FALSE ;
}
