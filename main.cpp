// #include "bfsSolver.cpp"
// #include "dfsSolver.cpp"
// #include "iddfsSolver.cpp"
#include "idastar.cpp"
int main(){
    RubiksCube cube;
    vector<CubeBase::MOVE> moves = cube.randomShuffle(11);
    cout<<"Shuffled:  ";
    for(auto m : moves){
        cout<<CubeBase::getMove(m)<<" ";
    }
    cout<< endl;
    cout<<"\n";
    cube.print();

    // bfsSolver solver(cube);
    // vector<CubeBase::MOVE> solution = solver.solve();
    // cout<<"Solution:";
    // for(auto m : solution){
    //     cout<<CubeBase::getMove(m)<<" ";
    // }
    // cout<< endl;

    // dfsSolver solver(cube);
    // vector<CubeBase::MOVE> solution = solver.solve();
    // cout<<"Solution:";
    // for(auto m : solution){
    //     cout<<CubeBase::getMove(m)<<" ";
    // }

    
    // iddfsSolver solver(cube);
    // vector<CubeBase::MOVE> solution = solver.solve();
    // cout<<"Solution:";
    // for(auto m : solution){
    //     cout<<CubeBase::getMove(m)<<" ";
    // }
    // cout<< endl;

    // string filename = "PatternDatabases/CornerDB.txt";
    // CornerDBMaker dbMaker(filename);
    // cout<<"Making DB..."<<endl;
    // dbMaker.bfsAndStore();
    // cout<<"Done!"<<endl;
    cout<<"\n\n";
    IDAstarSolver solver(cube,"/home/ajay/myfiles/coding/RubiksCube/PatternDatabases/CornerDatabase.txt");
    vector<CubeBase::MOVE> solution = solver.solve();
    cout<<"Solution:  ";
    for(auto m : solution){
        cout<<CubeBase::getMove(m)<<" ";
    }
    cout<< endl;
    cout<<"\n";
    solver.rubiksCube.print();

    return 0;
}