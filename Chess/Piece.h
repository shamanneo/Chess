#pragma once
#include <cmath> 
#include <objidl.h> 
#include <gdiplus.h>

enum 
{
    WHITEPAWN = 90,
    WHITEROOK,
    WHITEKNIGHT,
    WHITEBISHOP,
    WHITEQUEEN,
    WHITEKING,
    BLACKPAWN,
    BLACKROOK,
    BLACKKNIGHT,
    BLACKBISHOP,
    BLACKQUEEN,
    BLACKKING
} ; 

class CChessBoard ; 
class CPiece
{
    private : 
        int m_x ; 
        int m_y ; 
        CChessBoard *m_chess_board ; 
        HWND m_hwnd ; 
    public :
        CPiece(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        virtual ~CPiece() ; 
    public :    
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) ; 
        bool Move(int tar_x, int tar_y) ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) ;
        inline virtual int GetColor() const  ; 
        inline virtual int GetID() const ; 
        inline int GetX() const ; 
        inline int GetY() const ; 
        void SetXY(int x, int y) ; 
        CChessBoard *GetChessBoard() const ; 
        HWND Gethwnd() const ; 
        void AfterMove(int cur_x, int cur_y, int tar_x, int tar_y, CPiece &tar_piece) ;
} ;

inline int CPiece::GetColor() const
{
    return 0 ;
}

inline int CPiece::GetID() const
{
    return 0 ; 
}

inline int CPiece::GetX() const
{
    return m_x ;
}

inline int CPiece::GetY() const
{
    return m_y ;
}


