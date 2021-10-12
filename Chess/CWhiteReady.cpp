#include "CWhiteReady.h"
#include "CChessGame.h"

extern CChessBoard chess_board ; 

CPiece *CWhiteReady::Move(CPiece *prev, int x, int y)
{
    CPiece *cur = chess_board.GetPiece(x, y) ; 
    if (prev == cur)
    {
        return cur ; 
    }
    else if ((cur != nullptr) && (prev->GetColor() == 1) && (cur->GetColor() == 1))
    {
        m_chess_game->SetWhiteTurnState() ; 
        m_chess_game->Picked(x, y) ; 
        return cur ;
    }
    else if (prev->Move(x, y))
    {
        m_chess_game->SetBlackTurnState() ; 
        return nullptr ;
    }
    return prev ; 
}