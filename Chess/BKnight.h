#include "Piece.h"

class CBKnight : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"black_knight.png" ; 
        const int m_color = 0 ;
        const int m_id = BLACKKNIGHT ; 
        Gdiplus::Image m_img ;
    public :
        CBKnight(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CBKnight() ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ;
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ;
} ;

inline int CBKnight::GetColor() const
{
    return m_color ;
}

inline int CBKnight::GetID() const
{
    return m_id ; 
}