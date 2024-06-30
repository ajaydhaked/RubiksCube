#include "BitCube.cpp"

class bfsSolver{
    private:
    vector<CubeBase::MOVE> moves;
    unordered_map<RubiksCube,bool,HashCube> visited; 
    unordered_map<RubiksCube,RubiksCube::MOVE,HashCube> performedMoves;

    RubiksCube bfs(){
        queue<RubiksCube> q;
        q.push(cube);
        visited[cube] = true;
        while(!q.empty()){
            RubiksCube cur = q.front();
            q.pop();
            if( cur.isSolved() )return cur;
            for(int i = 0; i < 18; i++){
                cur.move( RubiksCube::MOVE(i) );
                if( visited.find(cur) == visited.end() ){
                    visited[cur] = true;
                    performedMoves[cur] = RubiksCube::MOVE(i);
                    q.push(cur);
                }
                cur.invert( RubiksCube::MOVE(i) );
            }
        }
        return cube;
    }
    public:
    RubiksCube cube;

    bfsSolver(RubiksCube init){
        this->cube = init;
    }

    vector<CubeBase::MOVE> solve(){
        RubiksCube solved = bfs();
        assert ( solved.isSolved() );
        while(!(solved == cube)){
            moves.push_back( performedMoves[solved] );
            solved.invert( performedMoves[solved] );
        }
        cube=solved;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};