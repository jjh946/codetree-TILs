#include <iostream>

using namespace std;

int a, b, c;

int Min(int a, int b, int c){
    int min = 100;
    if (a<min){
        min = a;
    }
    if (b<min){
        min = b;
    }
    if (c<min){
        min = c;
    }
    return min;
}

int main() {
    cin >> a >> b >> c;

    // Write your code here!
    cout << Min(a,b,c);

    return 0;
}