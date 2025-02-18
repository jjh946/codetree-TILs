#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[91] = {0};

int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

	return 0;
}