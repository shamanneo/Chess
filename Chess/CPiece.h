#pragma once
#include <Windows.h>
#include <objidl.h> 
#include <gdiplus.h>

class CPiece
{
    private : 
        int m_x ; 
        int m_y ; 
    public :
        CPiece(int x, int y)
            : m_x(x), m_y(y) { }
        virtual void Draw(HDC hdc, int x, int y) 
        {
            return ; 
        }
        bool Move(int tar_x, int tar_y) ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) ;
        inline virtual int GetColor() const 
        {
            return 0 ; 
        }
        inline int GetX() const
        {
            return m_x ; 
        }
        inline int GetY() const
        {
            return m_y ;
        }
        inline void SetXY(int x, int y)
        {
            m_x = x ; 
            m_y = y ; 
        }
} ;


