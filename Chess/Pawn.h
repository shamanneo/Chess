#pragma once
#include "Piece.h"

class CPawn
{
    public :
        bool Up(int x, int y, CPiece *p1, CPiece *p2, bool &is_moved) ;
        bool Down(int x, int y, CPiece *p1, CPiece *p2, bool &is_moved) ; 
        bool IsUpPromotion(int x, int y, int tar_y) ; 
        bool IsDownPromotion(int x, int y, int tar_y) ; 
} ;

