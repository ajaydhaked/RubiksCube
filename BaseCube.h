#include <bits/stdc++.h>

using namespace std;

// Assumptions 

// CubeSides

//   U
// L F R B
//   D

//         W W W
//         W W W
//         W W W

//  G G G  R R R  B B B  O O O
//  G G G  R R R  B B B  O O O
//  G G G  R R R  B B B  O O O

//         Y Y Y
//         Y Y Y
//         Y Y Y

// Moves on rubicscube
// F, F', F2
// U, U', U2
// L, L', L2
// R, R', R2
// B, B', B2 
// D, D', D2




class CubeBase {
    public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    
    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE{
        F,FDASH,F2,
        L,LDASH,L2,
        R,RDASH,R2,
        U,UDASH,U2,
        B,BDASH,B2,
        D,DDASH,D2,
    };

    virtual COLOR getColor( FACE face, int row, int col) const = 0;
    static char getColorLetter ( COLOR col);
    virtual bool isSolved() = 0;
    static string getMove( MOVE mov ) ;
    void print() const ;
    vector<MOVE> randomShuffle( unsigned int n );
    CubeBase &move( MOVE mov ) ;
    CubeBase &invert ( MOVE mov) ;
    virtual CubeBase& f() = 0;
    // virtual CubeBase& fdash() = 0;
    // virtual CubeBase& f2() = 0;
    virtual CubeBase& u() = 0;
    // virtual CubeBase& udash() = 0;
    // virtual CubeBase& u2() = 0;
    virtual CubeBase& l() = 0;
    // virtual CubeBase& ldash() = 0;
    // virtual CubeBase& l2() = 0;
    virtual CubeBase& r() = 0;
    // virtual CubeBase& rdash() = 0;
    // virtual CubeBase& r2() = 0;
    virtual CubeBase& b() = 0;
    // virtual CubeBase& bdash() = 0;
    // virtual CubeBase& b2() = 0;
    virtual CubeBase& d() = 0;
    // virtual CubeBase& ddash() = 0;
    // virtual CubeBase& d2() = 0;

    string getCornerColorString(uint8_t ind) const;
    uint8_t getCornerIndex(uint8_t ind) const;
    uint8_t getCornerOrientation(uint8_t ind) const;

};