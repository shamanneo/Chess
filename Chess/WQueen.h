#include "Piece.h"

class CWQueen : public CPiece
{
    private : 
        const WCHAR *m_imgfile_name = L"white_queen.png" ; 
        const int m_color = 1 ;
        const int m_id = WHITEQUEEN ; 
        Gdiplus::Image m_img ; 
    public :
        CWQueen(int x, int y, CChessBoard *chess_board, HWND hwnd) ;
        ~CWQueen() ;
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ; 
} ;

inline int CWQueen::GetColor() const
{
    return m_color ;
}

inline int CWQueen::GetID() const
{
    return m_id ;
}