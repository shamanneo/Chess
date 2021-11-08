#pragma once
#include "resource.h"
#include <objidl.h> 
#include <gdiplus.h>
#include "ChessBoardWindow.h"

class CMainWindow
{ 
    protected : 
        void OnComamnd(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
        void OnPaint(HWND hwnd) ; 
        void OnDestory() ; 
    public :
        CMainWindow() = default ;
        LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) ;
} ;

