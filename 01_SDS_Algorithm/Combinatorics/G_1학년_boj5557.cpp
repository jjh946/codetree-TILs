#include <iostream>
using namespace std;

int n;
int nums[105];

long long dp[104][21];

//경우의 수를 다 계산하는 문제

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];

	int target = nums[n - 1];
	

	dp[0][nums[0]] = 1;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
            //j+nums[i]나 j - nums[i] 이 범위를 벗어나는 경우가 생길 수 있다.
            if (j+nums[i]>=0 && j+nums[i]<=20){
                if(j-nums[i]>=0 && j-nums[i]<=20){
                    dp[i][j] = dp[i - 1][j + nums[i]] + dp[i - 1][j - nums[i]];
                }
                else{
                    dp[i][j] = dp[i - 1][j + nums[i]];
                }
            }
			else{
                if(j-nums[i]>=0 && j-nums[i]<=20){
                    dp[i][j] = dp[i - 1][j - nums[i]];
                }
                
            }
		}
	}
	cout << dp[n - 2][target] << endl;
	return 0;
}