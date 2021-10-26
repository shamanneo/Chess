#pragma once
#include "Piece.h"
#include "WhiteTurn.h"
#include "WhiteReady.h"
#include "BlackTurn.h"
#include "BlackReady.h"
#include "ChessBoardWindow.h"

class CChessGame
{
    private :
        CState *m_whiteturn ;
        CState *m_whiteready ;
        CState *m_blackturn ;
        CState *m_blackready ;
        CState *m_state ;
        CPiece *m_prev ; 
    public :
        CChessGame(CChessBoard *chess_board) ; 
        ~CChessGame() ; 
        void WhiteSelect(int x, int y) ;
        void WhiteMove(int x, int y) ;
        void BlackSelect(int x, int y) ;
        void BlackMove(int x, int y) ;
        CState *GetWhiteTurnState() ;
        CState *GetWhiteReadyState() ;
        CState *GetBlackTurnState() ;
        CState *GetBlackReadyState() ;
        void SetState(CState *state) ; 
        void GameState(int x, int y) ; 
        CPiece *GetPrevPiece() const ; 
} ;

