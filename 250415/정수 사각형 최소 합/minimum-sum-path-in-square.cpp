#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[103][103];
int dp[103][103];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    fill(&dp[0][0], &dp[0][0] + 103*103, 1e9);
    dp[1][n] = grid[1][n];
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            
            if (dp[i-1][j] < 100000000 || dp[i][j+1] < 100000000){
                dp[i][j] = min(dp[i-1][j],dp[i][j+1]) + grid[i][j];
            }
            
        }
    }

    cout << dp[n][1];

    return 0;
}
