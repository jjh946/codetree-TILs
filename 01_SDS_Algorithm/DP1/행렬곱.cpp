#include <iostream>
#include <algorithm>
using namespace std;

int n, r, c;
int rc[505][2];
int memo[505][505];

int D(int s, int e) {
	
	if (memo[s][e]) {
		return memo[s][e];
	}

	if (s == e) return memo[s][e] = 0;
	if (e == s + 1) {
		return memo[s][e] = rc[s][0] * rc[s][1] * rc[e][1];
	} //여기 초기 값 구해주는 거에서 실수가 있었다

	int mn = (1 << 31) - 1;
	for (int k = s; k < e; k++) { // 이것도 k <= e 가 메모리 초과의 범인이긴 했다.
		mn = min(mn, D(s, k) + D(k + 1, e) + rc[s][0] * rc[k][1] * rc[e][1]);
	}


	memo[s][e] = mn;
	//cout << mn << endl;
	return mn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rc[i][0] >> rc[i][1];
	}

	
	cout << D(1, n);



	return 0;
}