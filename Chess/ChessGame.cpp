#include "ChessGame.h"

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