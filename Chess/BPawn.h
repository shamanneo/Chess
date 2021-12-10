#include "Piece.h"
#include "Pawn.h" 

class CBPawn : public CPiece, public CPawn 
{
    private :
        const WCHAR *m_imgfile_name = L"black_pawn.png" ; 
        const int m_color = 0 ;
        const int m_id = BLACKPAWN ; 
        bool m_is_moved ; 
        bool m_forward_direction ; // If direction is true, the pawn will move upward.
        Gdiplus::Image m_img ;
    public : 
        CBPawn(int x, int y, CChessBoard *chess_board, HWND hwnd, bool forword_direction = false) ;
        ~CBPawn() ;
    public :
        virtual void Draw(const int size, Gdiplus::Graphics *graphics, int x, int y) override ;
        virtual bool CanMove(int cur_x, int cur_y, int tar_x, int tar_y) override ; 
        inline virtual int GetColor() const ; 
        inline virtual int GetID() const ; 
        void Promotion(int cur_x, int cur_y, int tar_x, int tar_y) ;
} ;

inline int CBPawn::GetColor() const
{
    return m_color ;
}

inline int CBPawn::GetID() const
{
    return m_id ; 
}