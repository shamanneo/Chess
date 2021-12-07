#include "Piece.h"

class CWRook : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"white_rook.png" ; 
        const int m_color = 1 ;
        const int m_id = WHITEROOK ; 
        bool m_can_castle ;
        Gdiplus::Image m_img ;
    public :
        CWRook(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CWRook() ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ; 
        bool CanCastling() const ; 
} ;

inline int CWRook::GetColor() const
{
    return m_color ;
}

inline int CWRook::GetID() const
{
    return m_id ;
}