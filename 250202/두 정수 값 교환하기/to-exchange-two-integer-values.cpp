#include <iostream>

using namespace std;

int n, m;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout << a << ' ' << b;
}


int main() {
    cin >> n >> m;

    // Write your code here!
    swap(n,m);

    return 0;
}