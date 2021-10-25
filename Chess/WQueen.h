#include "Piece.h"

class CWQueen : public CPiece
{
    private : 
        const WCHAR *m_imgfile_name = L"white_queen.png" ; 
        const int m_color = 1 ;
    public :
        CWQueen(int nX, int nY)
            : CPiece(nX, nY) { } 
        virtual void Draw(HDC hdc, int x, int y) override ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const
        {
            return m_color ;
        }
} ;

