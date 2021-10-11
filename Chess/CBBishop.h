#include "CPiece.h"

class CBBishop : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"black_bishop.png" ; 
        const int m_color = 0 ;
    public :
        CBBishop(int x, int y)
            : CPiece(x, y) { }
        virtual void Draw(HDC hdc, int x, int y) override ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ;
        inline virtual int GetColor() const
        {
            return m_color ; 
        }
} ;
