#include "Piece.h"

class CBPawn : public CPiece
{
    private :
        const WCHAR *m_imgfile_name = L"black_pawn.png" ; 
        const int m_color = 0 ;
        bool m_is_moved ; 
        Gdiplus::Image m_img ;
    public : 
        CBPawn(int x, int y, CChessBoard *chess_board, HWND hwnd) ;
        ~CBPawn() ;
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const ; 
        void Promotion(int cur_x, int cur_y, int tar_x, int tar_y) ;
} ;
