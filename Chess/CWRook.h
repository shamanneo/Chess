#include "CPiece.h"

class CWRook : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"white_rook.png" ; 
        const int m_color = 1 ;
    public :
        CWRook(int x, int y)
            : CPiece(x, y) { }
        virtual void Draw(HDC hdc, int x, int y) override ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const
        {
            return m_color ;
        }
} ;

