#include "Piece.h"

class CWPawn : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"white_pawn.png" ; 
        const int m_color = 1 ;
        bool m_is_moved_ = false ;
    public :
        CWPawn(int x, int y)
            : CPiece(x, y) { } 
        virtual void Draw(HDC hdc, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) ;
        inline virtual int GetColor() const
        {
            return m_color ;
        }
} ; 
