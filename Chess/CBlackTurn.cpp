#include "CBlackTurn.h"
#include "CChessGame.h"

extern CChessBoard chess_board ;

bool CBlackTurn::IsPicked(CPiece *prev, CPiece *cur)
{
    if (prev == cur)
    {
        return false ;
    }

    else if (cur != nullptr && cur->GetColor() == 1)
    {
        return false ;
    }
    else
    {
        if (prev != nullptr)
        {
            chess_board.ErasePrevPos(prev->GetX(), prev->GetY()) ;
        }
        chess_board.DrawCurrentPos(cur->GetX(), cur->GetY()) ;
        return true ;
    }
}

CPiece *CBlackTurn::Pick(CPiece *prev, int x, int y)
{
    CPiece *cur = chess_board.GetPiece(x, y) ;
    if (IsPicked(prev, cur))
    {
        m_chess_game->SetBlackReadyState() ;
        return cur ;
    }
    else
    {
        return nullptr ; 
    }
}
