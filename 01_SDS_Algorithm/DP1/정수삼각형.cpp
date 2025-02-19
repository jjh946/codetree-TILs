#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long A[502][502];
long long dp[502][502];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> A[i][j];
			
		}
		
	}

	dp[1][1] = A[1][1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = A[i][j] + max(dp[i - 1][j - 1] , dp[i - 1][j]); //삼각형 바깥쪽은 0으로 초기화 되어있다.
			
		}
		
	}
	
	long long Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dp[n][i]);
	}
	cout << Max;

	return 0;
}