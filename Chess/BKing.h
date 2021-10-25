#include "Piece.h"

class CBKing : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"black_king.png" ; 
        const int m_color = 0 ;
        bool m_can_castle ;
    public :
        CBKing(int x, int y)
            : CPiece(x, y), m_can_castle(true) { }
        virtual void Draw(HDC hdc, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const
        {
            return m_color ;
        }
        bool KingSideCastling() ;
        bool QueenSideCastling() ;
        bool IsCheckMated() ;
} ; 
