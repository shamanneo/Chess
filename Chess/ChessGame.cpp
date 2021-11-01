#include "ChessGame.h"

CChessGame::CChessGame(CChessBoard *chess_board, CPaintChessBoard *paint_board)
{
    m_whiteturn = new CWhiteTurn(this, chess_board, paint_board) ;
    m_whiteready = new CWhiteReady(this, chess_board, paint_board) ;
    m_blackturn = new CBlackTurn(this, chess_board, paint_board) ;
    m_blackready = new CBlackReady(this, chess_board, paint_board) ;
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

bool CChessGame::WhiteSelect(int x, int y)
{
    return m_state->WhiteSelect(x, y) ; 
}

bool CChessGame::WhiteMove(int x, int y)
{
    return m_state->WhiteMove(x, y) ; 
}

bool CChessGame::BlackSelect(int x, int y)
{
    return m_state->BlackSelect(x, y) ; 
}

bool CChessGame::BlackMove(int x, int y)
{
    return m_blackready->BlackMove(x, y) ; 
}

CState *CChessGame::GetWhiteTurnState()
{
    return m_whiteturn ;
}

CState *CChessGame::GetWhiteReadyState()
{
    return m_whiteready ;
}

CState *CChessGame::GetBlackTurnState()
{
    return m_blackturn ;
}

CState *CChessGame::GetBlackReadyState()
{
    return m_blackready ;
}

void CChessGame::SetState(CState *state)
{
    m_state = state ; 
}

void CChessGame::GameState(int x, int y)
{
    if (WhiteSelect(x, y))
    {
        
    }
    else if (WhiteMove(x, y))
    {
        m_prev = nullptr ; 
        return ; 
    }
    else if (BlackSelect(x, y))
    {

    }
    else if (BlackMove(x, y))
    {
        m_prev = nullptr ;
        return ;
    }
    m_prev = m_state->GetChessBoard()->GetPiece(x, y) ; 
}

CPiece *CChessGame::GetPrevPiece() const
{
    return m_prev ; 
}