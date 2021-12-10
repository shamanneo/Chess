#include "Piece.h"
#include "Pawn.h" 

class CWPawn : public CPiece, public CPawn 
{
    private :
        const WCHAR *m_imgfile_name = L"white_pawn.png" ; 
        const int m_color = 1 ;
        const int m_id = WHITEPAWN ; 
        bool m_is_moved ; 
        bool m_forward_direction ; // If direction is true, the pawn will move upward.
        Gdiplus::Image m_img ;
    public :
        CWPawn(int x, int y, CChessBoard *chess_board, HWND hwnd, bool forward_direction = true) ; 
        ~CWPawn() ; 
    public :
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ; 
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ;
        inline virtual int GetColor() const ;
        inline virtual int GetID() const ; 
        void Promotion(int cur_x, int cur_y, int tar_x, int tar_y) ; 
} ; 

inline int CWPawn::GetColor() const
{
    return m_color ;
}

inline int CWPawn::GetID() const
{
    return m_id ;
}