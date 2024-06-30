#include "BitCube.cpp"

class dfsSolver{
    vector<CubeBase::MOVE> performedMoves;
    int maxDepth;

    bool dfs(int dep){
        if( cube.isSolved() ){cout<<"found solved one"<<endl;return true;}
        if( dep == maxDepth )return false;
        for(int i = 0; i < 18; i++){
            cube.move( CubeBase::MOVE(i) );
            performedMoves.push_back( CubeBase::MOVE(i) );
            if( dfs(dep+1) )return true;
            cube.invert( CubeBase::MOVE(i) );
            performedMoves.pop_back();
        }
        return false;
    }

    public:
    RubiksCube cube;

    dfsSolver(RubiksCube init, int maxDepth = 8){
        this->cube = init;
        this->maxDepth = maxDepth;
    }

    vector<CubeBase::MOVE> solve(){
        dfs(0);
        return performedMoves;
    }
};