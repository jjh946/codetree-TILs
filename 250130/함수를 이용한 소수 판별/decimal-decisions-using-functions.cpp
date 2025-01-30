#include <iostream>

using namespace std;

int a, b;

bool IsPrime(int n) {
    for (int i = 2; i < n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> a >> b;

    // Write your code here!
    int sum = 0;
    for( int i=a;i<b+1;i++){
        if (IsPrime(i)){
            sum += i;
        }
    }
    cout << sum;

    return 0;
}