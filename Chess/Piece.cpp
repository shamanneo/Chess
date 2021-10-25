#include "Piece.h"
#include "ChessBoard.h"

extern CChessBoard chess_board ;

bool CPiece::Move(int tar_x, int tar_y)
{
    if (!this->CanMove(this->GetX(), this->GetY(), tar_x, tar_y))
    {
        return false ;
    }
    chess_board.SetPieces(tar_x, tar_y, this->GetX(), this->GetY(), *this) ;
    this->SetXY(tar_x, tar_y) ; 
    return true ;
}

bool CPiece::CanMove(int cur_x, int cur_y, int tar_x, int tar_y)
{
    CPiece *cur_pos = chess_board.GetPiece(cur_x, cur_y) ; 
    CPiece *tar_pos = chess_board.GetPiece(tar_x, tar_y) ;
    if (tar_pos == nullptr)
    {
        return true ; 
    }
    return (cur_pos->GetColor() != tar_pos->GetColor()) ; 
}