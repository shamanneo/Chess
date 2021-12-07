#include "Piece.h"

class CWBishop : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"white_bishop.png" ; 
        const int m_color = 1 ;
        const int m_id = WHITEBISHOP ; 
        Gdiplus::Image m_img ;
    public :
        CWBishop(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CWBishop() ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) ;
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ; 
} ;

inline int CWBishop::GetColor() const
{
    return m_color ; 
}

inline int CWBishop::GetID() const
{
    return m_id ; 
}



