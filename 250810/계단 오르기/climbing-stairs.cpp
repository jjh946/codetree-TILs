#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1005];

int main() {
    cin >> n;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=n+5;i++){
        dp[i]=(dp[i-2] + dp[i-3])/10007;
    }

    cout << dp[n];

    return 0;
}