#include <iostream>

using namespace std;

int a, b;

bool IstOnjunsu(int n){
    if (n%2==0) return false;
    if (n%10==5) return false;
    if (n%3==0 && n%9!=0) return false;
    return true;
}

int main() {
    cin >> a >> b;

    // Write your code here!
    int cnt=0;
    for (int i=a;i<b+1;i++){
        if (IstOnjunsu(i)) cnt++;
    }
    cout << cnt;

    return 0;
}