#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[105][105];
int dp[105][105];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = grid[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!dp[i][j])
                dp[i][j]=grid[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][n];


    // Please write your code here.

    return 0;
}
