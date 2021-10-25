#include "WhiteTurn.h"
#include "ChessGame.h"

extern CChessBoard chess_board ;

bool CWhiteTurn::IsPicked(CPiece *prev, CPiece *cur)
{
    if (prev == cur)
    {
        return false ;
    }
    else if (cur != nullptr && cur->GetColor() == 0)
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

CPiece *CWhiteTurn::Pick(CPiece *prev, int x, int y)
{
    
    CPiece *cur = chess_board.GetPiece(x, y) ;
    if (IsPicked(prev, cur))
    {
        m_chess_game->SetWhiteReadyState() ; 
        return cur ;
    }
    else
    {
        return nullptr ; 
    }
}