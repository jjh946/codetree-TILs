#include <iostream>

using namespace std;

int M, D;


bool IsDateExist (int m, int d){
    if (m>12) return false;
    else {
        if (m==2){
            if (d>28) return false;
            else return true;
        } 
        if (m==4 || m==6 || m==8 || m==9 || m==11) {
            if (d>30) return false;
            else return true;
        }
        else {
            if (d>31) return false;
            else return true;
        }
        
    }
}


int main() {
    cin >> M >> D;

    // Write your code here!
    if (IsDateExist(M,D)) cout << "Yes";
    else cout << "No";
    return 0;
}