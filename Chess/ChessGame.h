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
        CChessGame() ; 
        ~CChessGame() ; 
        void WhiteSelect() ; 
        void WhiteMove() ; 
        void BlackSelect() ; 
        void BlackMove() ; 

        void SetWhiteTurnState() ; 
        void SetWhiteReadyState() ;
        void SetBlackTurnState() ; 
        void SetBlackReadyState() ; 
        void Picked(int x, int y) ;
} ;

