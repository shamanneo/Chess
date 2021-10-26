#include "ChessGame.h"

CChessGame::CChessGame()
{
    m_whiteturn = new CWhiteTurn(this) ;
    m_whiteready = new CWhiteReady(this) ;
    m_blackturn = new CBlackTurn(this) ;
    m_blackready = new CBlackReady(this) ;
    m_state = m_whiteturn ;
    m_prev = nullptr ;
}

CChessGame::~CChessGame()
{
    delete m_whiteturn ; 
    delete m_whiteready ;
    delete m_blackturn ;
    delete m_blackready ;
}

void CChessGame::WhiteSelect()
{
    
}

void CChessGame::WhiteMove()
{

}

void CChessGame::BlackSelect()
{

}

void CChessGame::BlackMove()
{

}

void CChessGame::SetWhiteTurnState()
{
    m_state = m_whiteturn ;
}

void CChessGame::SetWhiteReadyState()
{
    m_state = m_whiteready ;
}

void CChessGame::SetBlackTurnState()
{
    m_state = m_blackturn ;
}

void CChessGame::SetBlackReadyState()
{
    m_state = m_blackready ;
}

CState *CChessGame::GetWhiteTurnState() const
{
    return m_whiteturn ; 
}

CState *CChessGame::GetWhiteReadyState() const
{
    return m_whiteready ; 
}

CState *CChessGame::GetBlackTurnState() const
{
    return m_blackturn ; 
}

CState *CChessGame::GetBlackReadyState() const
{
    return m_blackready ; 
}

void CChessGame::Picked(int x, int y)
{
    if (m_state == m_whiteturn)
    {
        m_prev = m_state->Pick(m_prev, x, y) ;
    }
    else if (m_state == m_whiteready)
    {
        m_prev = m_state->Move(m_prev, x, y) ;
    }
    else if (m_state == m_blackturn)
    {
        m_prev = m_state->Pick(m_prev, x, y) ;
    }
    else if (m_state == m_blackready)
    {
        m_prev = m_state->Move(m_prev, x, y) ;
    }
}