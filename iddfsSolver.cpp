#include "dfsSolver.cpp"

class iddfsSolver{
    private:
    int max_depth;
    vector<CubeBase::MOVE> moves;

    public:
    RubiksCube cube;

    iddfsSolver(RubiksCube init, int max_depth = 7){
        this->cube = init;
        this->max_depth = max_depth;
    }

    vector<CubeBase::MOVE> solve(){
        for(int i = 0; i <= max_depth; i++){
            dfsSolver solver(cube, i);
            moves = solver.solve();
            if( solver.cube.isSolved() ){
                cube = solver.cube;
                break;
            }
        }
        return moves;
    }
};