#include "Piece.h"

class CBKing : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"black_king.png" ; 
        const int m_color = 0 ;
        bool m_can_castle ;
        Gdiplus::Image m_img ;
    public :
        CBKing(int x, int y, CChessBoard *chess_board, HWND hwnd) ; 
        ~CBKing() ; 
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const ; 
        bool KingSideCastling() ;
        bool QueenSideCastling() ;
        bool IsCheckMated() ;
} ; 
