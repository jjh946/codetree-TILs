#include <iostream>

using namespace std;

int a, b;

bool IsPrimeNumber (int n){
    if (n==1) return false;
    for(int i=2;i<n;i++){
        if (n%i==0) return false;
    }
    //cout << n << " is prime number"
    return true;
}

bool IsAddEven (int n) {
    int sum = 0;

    while(n%10!=0){
        sum += n%10;
        n /= 10;
    }

    if (sum%2==0) return true;
    else return false;
}

int main() {
    cin >> a >> b;

    // Write your code here!
    int cnt = 0;
    for (int i=a;i<b+1;i++){
        if (IsPrimeNumber(i) && IsAddEven(i)) cnt++;
    }
    cout << cnt;


    return 0;
}