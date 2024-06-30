#include "BaseCube.h"

//   0
// 1 2 3 4
//   5 


class RubiksCube : public CubeBase {
    private:

    void rotateFace( int ind ){
        char temp[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                temp[i][j] = cube[ind][i][j];
            }
        }
        for(int i = 0; i < 3; i++)cube[ind][0][i] = temp[2-i][0];
        for(int i = 0; i < 3; i++)cube[ind][i][2] = temp[0][i];
        for(int i = 0; i < 3; i++)cube[ind][2][i] = temp[2-i][2];
        for(int i = 0; i < 3; i++)cube[ind][i][0] = temp[2][i];
    }

    public:
    char cube[6][3][3];
    RubiksCube(){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor( FACE face, int row, int col) const override {
        if(cube[int(face)][row][col]=='W')return COLOR::WHITE;
        if(cube[int(face)][row][col]=='G')return COLOR::GREEN;
        if(cube[int(face)][row][col]=='R')return COLOR::RED;
        if(cube[int(face)][row][col]=='B')return COLOR::BLUE;
        if(cube[int(face)][row][col]=='O')return COLOR::ORANGE;
        if(cube[int(face)][row][col]=='Y')return COLOR::YELLOW;
        return COLOR::WHITE;
    }

    bool isSolved() override {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(cube[i][j][k] != getColorLetter(COLOR(i)))return false;
                }
            }
        }
        return true;
    }


    CubeBase& u() override {
        rotateFace(0);
        // up face
        char temp[3];
        // clockwise
        for (int i = 0; i < 3; i++)temp[i] = cube[2][0][i];
        for (int i = 0; i < 3; i++)cube[2][0][i] = cube[3][0][i];
        for (int i = 0; i < 3; i++)cube[3][0][i] = cube[4][0][i];
        for (int i = 0; i < 3; i++)cube[4][0][i] = cube[1][0][i];
        for (int i = 0; i < 3; i++)cube[1][0][i] = temp[i];
        return *this;
    }

    CubeBase& l() override {
        rotateFace(1);
        // left face
        char temp[3];
        // clockwise
        for(int i = 0; i < 3; i++)temp[i] = cube[0][i][0];
        for(int i = 0; i < 3; i++)cube[0][i][0] = cube[4][2-i][2];
        for(int i = 0; i < 3; i++)cube[4][i][2] = cube[5][2-i][0];
        for(int i = 0; i < 3; i++)cube[5][i][0] = cube[2][i][0];
        for(int i = 0; i < 3; i++)cube[2][i][0] = temp[i];
        return *this;
    }

    CubeBase& f() override {
        rotateFace(2);
        // front face
        char temp[3];
        // clockwise
        for(int i = 0; i < 3; i++)temp[i] = cube[0][2][i];
        for(int i = 0; i < 3; i++)cube[0][2][i] = cube[1][2-i][2];
        for(int i = 0; i < 3; i++)cube[1][i][2] = cube[5][0][i];
        for(int i = 0; i < 3; i++)cube[5][0][i] = cube[3][2-i][0];
        for(int i = 0; i < 3; i++)cube[3][i][0] = temp[i];
        return *this;
    }

    CubeBase& r() override {
        rotateFace(3);
        // right face
        char temp[3];
        // clockwise
        for(int i = 0; i < 3; i++)temp[i] = cube[0][i][2];
        for(int i = 0; i < 3; i++)cube[0][i][2] = cube[2][i][2];
        for(int i = 0; i < 3; i++)cube[2][i][2] = cube[5][i][2];
        for(int i = 0; i < 3; i++)cube[5][i][2] = cube[4][2-i][0];
        for(int i = 0; i < 3; i++)cube[4][i][0] = temp[2-i];
        return *this;
    }

    CubeBase& b() override {
        rotateFace(4);
        // back face
        char temp[3];
        // clockwise
        for(int i = 0; i < 3; i++)temp[i] = cube[0][0][i];
        for(int i = 0; i < 3; i++)cube[0][0][i] = cube[3][i][2];
        for(int i = 0; i < 3; i++)cube[3][i][2] = cube[5][2][2-i];
        for(int i = 0; i < 3; i++)cube[5][2][i] = cube[1][i][0];
        for(int i = 0; i < 3; i++)cube[1][2-i][0] = temp[i];
        return *this;
    }

    CubeBase& d() override {
        rotateFace(5);
        // down face
        char temp[3];
        // clockwise
        for(int i = 0; i < 3; i++)temp[i] = cube[2][2][i];
        for(int i = 0; i < 3; i++)cube[2][2][i] = cube[1][2][i];
        for(int i = 0; i < 3; i++)cube[1][2][i] = cube[4][2][i];
        for(int i = 0; i < 3; i++)cube[4][2][i] = cube[3][2][i];
        for(int i = 0; i < 3; i++)cube[3][2][i] = temp[i];
        
        return *this;
    }

    bool operator==(const RubiksCube &other) const {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(cube[i][j][k] != other.cube[i][j][k])return false;
                }
            }
        }
        return true;
    }

    RubiksCube& operator=(const RubiksCube &other){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    cube[i][j][k] = other.cube[i][j][k];
                }
            }
        }
        return *this;
    }



};

struct HashCube{
    size_t operator()(const RubiksCube &cube) const{
        string tmp = "";
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp += cube.cube[i][j][k];
                }
            }
        }
        return hash<string>()(tmp);
    }
};

