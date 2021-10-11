#include "CPiece.h"

class CWBishop : public CPiece
{
    private :
        const TCHAR *m_imgfile_name = L"white_bishop.png" ; 
        const int m_color = 1 ;
    public :
        CWBishop(int x, int y)
            : CPiece(x, y) { } 
        virtual void Draw(HDC hdc, int x, int y) override ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) ;
        inline virtual int GetColor() const
        {
            return m_color ;
        }
} ;






