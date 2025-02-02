#include <iostream>

using namespace std;

int Y, M, D;

bool IsYunNyeon (int y){
    if (y%4==0){
        if (y%100==0){
            if (y%400==0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

bool IsDateExist (int y, int m, int d){
    if (m==2){
        if (IsYunNyeon(y)){
            if (d>29) return false;
            else return true;
        }
        else{
            if (d>28) return false;
            else return true;
        }
    }
    else if (m==4||m==6||m==9||m==11){
        if (d>30) return false;
        else return true;
    }
    else{
        if (d>31) return false;
        else return true;
    }
}

int WhichSeason(int m){
    if (m>=3 && m<=5) cout << "Spring";
    else if (m>=6 && m<=8) cout << "Summer";
    else if (m>=9 && m<=11) cout << "Fall";
    else cout << "Winter";
    return 0;
}

int main() {
    cin >> Y >> M >> D;

    // Write your code here!
    if (IsDateExist(Y,M,D)) WhichSeason(M);
    else cout << -1;


    return 0;
}