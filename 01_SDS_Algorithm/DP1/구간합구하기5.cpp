#include <iostream>

using namespace std;

int n, m;
int A[1030][1030];
int dp[1030][1030];

int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + A[i][j];
		
		}

	}

	int x1, x2, y1, y2;
	for (int i = 1; i <= m; i++) {

		cin >> x1 >> y1 >> x2 >> y2;

		sum = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		cout << sum << '\n';
	}

	return 0;
}