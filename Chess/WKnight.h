#include "Piece.h"

class CWKnight : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"white_knight.png" ; 
        const int m_color = 1 ;
        Gdiplus::Image m_img ;
    public :
        CWKnight(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CWKnight() ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ;
        inline virtual int GetColor() const ; 
} ;

inline int CWKnight::GetColor() const
{
    return m_color ;
}
