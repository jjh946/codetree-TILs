#include <iostream>

using namespace std;

int y;

bool IsYunnyeon(int n){
    if (n%4!=0){
        return false;
    }
    if (n%100==0 && n%400!=0){
        return false;
    }
    return true;
}

int main() {
    cin >> y;

    // Write your code here!
    if (IsYunnyeon(y)) cout << "true";
    else cout << "false";

    return 0;
}