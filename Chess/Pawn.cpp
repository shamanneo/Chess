#include "Pawn.h"

bool CPawn::Up(int x, int y, CPiece *p1, CPiece *p2, bool &is_moved) 
{
    if (p1 != nullptr) // Attack.
    {
        if ((x == 1 && y == 1) || (x == -1 && y == 1))
        {
            return true ;
        }
        return false ; 
    }
    else if (x == 0 && y == 1) // General move. 
    {
        is_moved = true ;
        return true ;
    }
    else if (x == 0 && y == 2 && is_moved == false) // Move 2 spaces when first turn. 
    {
        if (p2 != nullptr)
        {
            return false ; 
        }
        is_moved = true ;
        return true ;
    }
    return false ;
}

bool CPawn::Down(int x, int y, CPiece *p1, CPiece *p2, bool &is_moved)
{
    if (p1 != nullptr) // Attack.
    {
        if ((x == 1 && y == -1) || (x == -1 && y == -1))
        {
            return true ;
        }
        return false ;
    }
    else if (x == 0 && y == -1) // General move.
    {
        is_moved = true ;
        return true ;
    }
    else if (x == 0 && y == -2 && is_moved == false) // Move 2 spaces when first turn. 
    {
        if (p2 != nullptr)
        {
            return false ;
        }
        is_moved = true ;
        return true ;
    }
    return false ;
}

bool CPawn::IsUpPromotion(int x, int y, int tar_y)
{
    if(tar_y != 0)
    {
        return false ; 
    }
    if((x == 1 && y == 1) || (x == -1 && y == 1) || (x == 0 && y == 1))
    {
        return true ; 
    }
    return false ; 
}

bool CPawn::IsDownPromotion(int x, int y, int tar_y) 
{
    if(tar_y != 7)
    {
        return false ; 
    }
    if((x == 1 && y == -1) || (x == -1 && y == -1) || (x == 0 && y == -1))
    {
        return true ; 
    }
    return false ; 
}