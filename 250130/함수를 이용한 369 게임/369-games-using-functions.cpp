#include <iostream>

using namespace std;

int a, b;

bool Is369 (int n){
    int tmp = n;
    while(tmp != 0){
        if (tmp%10==3 || tmp%10==6 || tmp%10==9){
            return 1;
        }
        tmp = tmp/10;
    }
    return 0;
}

int main() {
    cin >> a >> b;

    // Write your code here!
    int cnt=0;
    for (int i=a;i<b+1;i++){
        if (Is369(i) || i%3==0){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}