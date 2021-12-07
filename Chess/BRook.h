#include "Piece.h"

class CBRook : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"black_rook.png" ;
        const int m_color = 0 ;
        const int m_id = BLACKROOK ; 
        bool m_can_castle ;
        Gdiplus::Image m_img ;
    public :
        CBRook(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CBRook() ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ;
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ; 
        bool CanCastling() const ;
} ;

inline int CBRook::GetColor() const
{
    return m_color ;
}

inline int CBRook::GetID() const
{
    return m_id ;
}