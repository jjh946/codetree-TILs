#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, sum, mn;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    mn = 99999;
    for(int i = 0;i<n;i++){
        sum = 0;
        for(int j=0;j<n;j++){
            sum += A[j] * abs(i-j);
        }
        if (sum<mn){
            mn = sum;
        }
    }
    cout << mn;

    return 0;
}