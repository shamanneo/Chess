#pragma once
#include "CPiece.h"
#include "CWhiteTurn.h"
#include "CWhiteReady.h"
#include "CBlackTurn.h"
#include "CBlackReady.h"

class CChessGame
{
    private :
        CState *m_whiteturn ;
        CState *m_whiteready ;
        CState *m_blackturn ;
        CState *m_blackready ;
        CState *m_state  ;
        CPiece *m_prev ; 
    public :
        CChessGame()
        {
            m_whiteturn = new CWhiteTurn(this) ; 
            m_whiteready = new CWhiteReady(this) ; 
            m_blackturn = new CBlackTurn(this) ; 
            m_blackready = new CBlackReady(this) ;
            m_state = m_whiteturn ;
            m_prev = nullptr ; 
        }
        void Picked(int x, int y) ;
        inline void SetWhiteTurnState() 
        {
            m_state = m_whiteturn ; 
        }
        inline void SetWhiteReadyState() 
        {
            m_state = m_whiteready ; 
        }
        inline void SetBlackTurnState()
        {
            m_state = m_blackturn ;
        }
        inline void SetBlackReadyState()
        {
            m_state = m_blackready ; 
        }
        ~CChessGame()
        {
            delete m_whiteturn ; 
            delete m_whiteready ; 
            delete m_blackturn ; 
            delete m_blackready ; 
        }
} ;

