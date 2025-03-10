#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

void func(int x,int y){
    if (x > y){
        cout << x+25 << ' ';
        cout << y*2 << endl;
    }
    else {
        cout << x*2 << ' ';
        cout << y+25 << endl;
    }
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    func(a,b);
    
    return 0;
}