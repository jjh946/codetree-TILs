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

    // Please write your code here.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
    }

    cout << dp[n][n];

    return 0;
}
