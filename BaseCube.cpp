#include "BaseCube.h"

char CubeBase::getColorLetter(COLOR col){
    switch (col)
    {
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::WHITE:
            return 'W';
        case COLOR::YELLOW:
            return 'Y';
        default:
            return 'X';
    }
}

string CubeBase::getMove(MOVE mov){
    switch (mov)
    {
        case MOVE::F:
            return "F";
        case MOVE::FDASH:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::L:
            return "L";
        case MOVE::LDASH:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RDASH:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UDASH:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::B:
            return "B";
        case MOVE::BDASH:
            return "B'";
        case MOVE::B2:
            return "B2";
        case MOVE::D:
            return "D";
        case MOVE::DDASH:
            return "D'";
        case MOVE::D2:
            return "D2";
        default:
            return "X";
    }
}


void CubeBase::print()const {
    for(int i = 0; i < 3; i++){
        cout<<"       ";
        for(int j = 0; j < 3; j++){
            cout<<getColorLetter(getColor(FACE::UP,i,j))<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<getColorLetter(getColor(FACE::LEFT,i,j))<<" ";
        }
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorLetter(getColor(FACE::FRONT,i,j))<<" ";
        }
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorLetter(getColor(FACE::RIGHT,i,j))<<" ";
        }
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorLetter(getColor(FACE::BACK,i,j))<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 0; i < 3; i++){
        cout<<"       ";
        for(int j = 0; j < 3; j++){
            cout<<getColorLetter(getColor(FACE::DOWN,i,j))<<" ";
        }
        cout<<endl;
    }
}

CubeBase& CubeBase::move(MOVE mov){
    switch (mov){
        case MOVE::F:
            return f();
        case MOVE::FDASH:
            return f().f().f();
        case MOVE::F2:
            return f().f();
        case MOVE::L:
            return l();
        case MOVE::LDASH:
            return l().l().l();
        case MOVE::L2:
            return l().l();
        case MOVE::R:
            return r();
        case MOVE::RDASH:
            return r().r().r();
        case MOVE::R2:
            return r().r();
        case MOVE::U:
            return u();
        case MOVE::UDASH:
            return u().u().u();
        case MOVE::U2:
            return u().u();
        case MOVE::B:
            return b();
        case MOVE::BDASH:
            return b().b().b();
        case MOVE::B2:
            return b().b();
        case MOVE::D:
            return d();
        case MOVE::DDASH:
            return d().d().d();
        case MOVE::D2:
            return d().d();
        default:
            return *this;
    }
}

CubeBase& CubeBase::invert(MOVE mov){
    switch (mov){
        case MOVE::F:
            return this->f().f().f();
        case MOVE::FDASH:
            return this->f();
        case MOVE::F2:
            return this->f().f();
        case MOVE::L:
            return this->l().l().l();
        case MOVE::LDASH:
            return this->l();
        case MOVE::L2:
            return this->l().l();
        case MOVE::R:
            return this->r().r().r();
        case MOVE::RDASH:
            return this->r();
        case MOVE::R2:
            return this->r().r();
        case MOVE::U:
            return this->u().u().u();
        case MOVE::UDASH:
            return this->u();
        case MOVE::U2:
            return this->u().u();
        case MOVE::B:
            return this->b().b().b();
        case MOVE::BDASH:
            return this->b();
        case MOVE::B2:
            return this->b().b();
        case MOVE::D:
            return this->d().d().d();
        case MOVE::DDASH:
            return this->d();
        case MOVE::D2:
            return this->d().d();
        default:
            return *this;
    }
}

vector<CubeBase::MOVE> CubeBase::randomShuffle(unsigned int n){
    vector<MOVE> moves;
    srand(time(0));
    for(int i = 0; i < n; i++){
        moves.push_back(static_cast<MOVE>(rand()%18));
        this->move(moves.back());
    }
    return moves;
}

string CubeBase::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}


uint8_t CubeBase::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t CubeBase::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}