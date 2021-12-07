#include "ChessBoard.h"
#include "Header.h"

CChessBoard::CChessBoard(HWND hwnd)
{
    Clear() ; 
    Reset(hwnd) ;
}

CChessBoard::~CChessBoard()
{
    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            if (m_chess_board[x][y] != nullptr)
            {
                delete m_chess_board[x][y] ; 
            }
        }
    }
}

void CChessBoard::Clear()
{
    for (int x = 0 ; x < 8 ; x++)
    {
        for (int y = 0 ; y < 8 ; y++)
        {
            m_chess_board[x][y] = nullptr ;
        }
    }
}

void CChessBoard::Reset(HWND hwnd)
{
    m_chess_board[0][0] = new CBRook(0, 0, this, hwnd) ;
    m_chess_board[1][0] = new CBKnight(1, 0, this, hwnd) ;
    m_chess_board[2][0] = new CBBishop(2, 0, this, hwnd) ;
    m_chess_board[3][0] = new CBQueen(3, 0, this, hwnd) ;
    m_chess_board[4][0] = new CBKing(4, 0, this, hwnd) ;
    m_chess_board[5][0] = new CBBishop(5, 0, this, hwnd) ;
    m_chess_board[6][0] = new CBKnight(6, 0, this, hwnd) ;
    m_chess_board[7][0] = new CBRook(7, 0, this, hwnd) ;

    m_chess_board[0][1] = new CBPawn(0, 1, this, hwnd) ;
    m_chess_board[1][1] = new CBPawn(1, 1, this, hwnd) ;
    m_chess_board[2][1] = new CBPawn(2, 1, this, hwnd) ;
    m_chess_board[3][1] = new CBPawn(3, 1, this, hwnd) ;
    m_chess_board[4][1] = new CBPawn(4, 1, this, hwnd) ;
    m_chess_board[5][1] = new CBPawn(5, 1, this, hwnd) ;
    m_chess_board[6][1] = new CBPawn(6, 1, this, hwnd) ;
    m_chess_board[7][1] = new CBPawn(7, 1, this, hwnd) ;

    m_chess_board[0][7] = new CWRook(0, 7, this, hwnd) ;
    m_chess_board[1][7] = new CWKnight(1, 7, this, hwnd) ;
    m_chess_board[2][7] = new CWBishop(2, 7, this, hwnd) ;
    m_chess_board[3][7] = new CWQueen(3, 7, this, hwnd) ;
    m_chess_board[4][7] = new CWKing(4, 7, this, hwnd) ;
    m_chess_board[5][7] = new CWBishop(5, 7, this, hwnd) ;
    m_chess_board[6][7] = new CWKnight(6, 7, this, hwnd) ;
    m_chess_board[7][7] = new CWRook(7, 7, this, hwnd) ;

    m_chess_board[0][6] = new CWPawn(0, 6, this, hwnd) ;
    m_chess_board[1][6] = new CWPawn(1, 6, this, hwnd) ;
    m_chess_board[2][6] = new CWPawn(2, 6, this, hwnd) ;
    m_chess_board[3][6] = new CWPawn(3, 6, this, hwnd) ;
    m_chess_board[4][6] = new CWPawn(4, 6, this, hwnd) ;
    m_chess_board[5][6] = new CWPawn(5, 6, this, hwnd) ;
    m_chess_board[6][6] = new CWPawn(6, 6, this, hwnd) ;
    m_chess_board[7][6] = new CWPawn(7, 6, this, hwnd) ;
}

void CChessBoard::CopyArrToBoard(int arr[], HWND hwnd)
{
    for(int x = 0 ; x < 8 ; x++)
    {
        for(int y = 0 ; y < 8 ; y++)
        {
            int piece_id = *(arr + y * 8 + x) ; 
            switch (piece_id)
            {
                case WHITEPAWN :
                {
                    m_chess_board[x][y] = new CWPawn(x, y, this, hwnd) ;
                    break ; 
                }
                case WHITEROOK :
                {
                    m_chess_board[x][y] = new CWRook(x, y, this, hwnd) ;
                    break ; 
                }
                case WHITEKNIGHT :
                {
                    m_chess_board[x][y] = new CWKnight(x, y, this, hwnd) ;
                    break ; 
                }
                case WHITEBISHOP :
                {
                    m_chess_board[x][y] = new CWBishop(x, y, this, hwnd) ;
                    break ; 
                }
                case WHITEQUEEN :
                {
                    m_chess_board[x][y] = new CWQueen(x, y, this, hwnd) ;
                    break ; 
                }
                case WHITEKING :
                {
                    m_chess_board[x][y] = new CWKing(x, y, this, hwnd) ;
                    break ; 
                }
                case BLACKPAWN :
                {
                    m_chess_board[x][y] = new CBPawn(x, y, this, hwnd) ;
                    break ;
                }
                case BLACKROOK :
                {
                    m_chess_board[x][y] = new CBRook(x, y, this, hwnd) ;
                    break ; 
                }
                case BLACKKNIGHT :
                {
                    m_chess_board[x][y] = new CBKnight(x, y, this, hwnd) ;
                    break ; 
                }
                case BLACKBISHOP :
                {
                    m_chess_board[x][y] = new CBBishop(x, y, this, hwnd) ;
                    break ; 
                }
                case BLACKQUEEN :
                {
                    m_chess_board[x][y] = new CBQueen(x, y, this, hwnd) ;
                    break ; 
                }
                case BLACKKING :
                {
                    m_chess_board[x][y] = new CBKing(x, y, this, hwnd) ;
                    break ; 
                }
                default :
                {
                    m_chess_board[x][y] = nullptr ; 
                    break ; 
                }
            }
        }
    }
}


void CChessBoard::SetPieces(int cur_x, int cur_y, int tar_x, int tar_y, CPiece &piece)
{
    if (m_chess_board[tar_x][tar_y] == nullptr) // just move.
    {
        m_chess_board[tar_x][tar_y] = &piece ;
    }
    else // attack. 
    {
        CPiece *temp = m_chess_board[tar_x][tar_y] ;
        m_chess_board[tar_x][tar_y] = &piece ; 
        delete temp ; 
    }
    m_chess_board[cur_x][cur_y] = nullptr ;
}



