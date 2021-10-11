#include "CBlackReady.h"
#include "CChessGame.h"

extern CChessBoard chess_board ;

CPiece *CBlackReady::Move(CPiece *prev, int x, int y)
{
    CPiece *cur = chess_board.GetPiece(x, y) ;
    if (prev == cur)
    {
        return cur ; 
    }
    else if ((cur != nullptr) && (prev->GetColor() == 0) && (cur->GetColor() == 0))
    {
        m_chess_game->SetBlackTurnState() ;
        m_chess_game->Picked(x, y) ;
        return cur ; 
    }
    else if (prev->Move(x, y))
    {
        prev->SetXY(x, y) ;
        m_chess_game->SetWhiteTurnState() ;
        return nullptr ;
    }
    return prev ;
}