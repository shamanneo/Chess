#include "Piece.h"

class CWQueen : public CPiece
{
    private : 
        const WCHAR *m_imgfile_name = L"white_queen.png" ; 
        const int m_color = 1 ;
        Gdiplus::Image m_img ; 
    public :
        CWQueen(int x, int y, CChessBoard *chess_board) ;
        virtual void Draw(const int size, Gdiplus::Graphics graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const ; 
} ;

