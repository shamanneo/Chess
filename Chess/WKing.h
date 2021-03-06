#include "Piece.h"

class CWKing : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"white_king.png" ; 
        const int m_color = 1 ;
        const int m_id = WHITEKING ; 
        bool m_can_castle ;
        Gdiplus::Image m_img ;
    public :
        CWKing(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CWKing() ;
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ;
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ; 
        bool KingSideCastling() ; 
        bool QueenSideCastling() ; 
        bool IsCheckMated() ; 
} ;

inline int CWKing::GetColor() const
{
    return m_color ;
}

inline int CWKing::GetID() const
{
    return m_id ;
}