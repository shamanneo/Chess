#pragma once
#include <cmath> 
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>

class CChessBoard ; 
class CPiece
{
    private : 
        int m_x ; 
        int m_y ; 
        CChessBoard *m_chess_board ; 
    public :
        CPiece(int x, int y, CChessBoard *chess_board) ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) ; 
        bool Move(int tar_x, int tar_y) ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) ;
        inline virtual int GetColor() const  ; 
        inline int GetX() const ; 
        inline int GetY() const ; 
        inline void SetXY(int x, int y) ; 
        CChessBoard *GetChessBoard() const ; 
} ;


