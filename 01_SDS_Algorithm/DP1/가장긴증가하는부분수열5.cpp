#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int n;
int A[1000004];
int dp[1000004];
pii A2[1000004];
int P[1000004];

stack<int> ans;


bool compare(pii a, pii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int get_max(int l, int r) {
	int mx=0;
	int mx_i;
	for (int i = l; i <= r; i++) {
		if (dp[i] > mx) {
			mx_i = i;
			mx = dp[i];
		}
		
	}
	P[r+1] = mx_i;
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A2[i] = { A[i],i };

	}
	sort(A2+1, A2 + n+1, compare);

	int idx;
	int mx = 0;
    int mx_i = 1;

	for (int i = 1; i <= n; i++) {

		idx = A2[i].second;
		dp[idx] = get_max(1, idx - 1) + 1;
		if (dp[idx] > mx) {
            mx = dp[idx];
            mx_i = idx;
        }
	}

    cout << mx << '\n';
  
    for(int i=mx;i>0;i--){
        ans.push(A[mx_i]);
        //cout << i <<'('<<mx_i<<')'<< A[mx_i] << ' ';
        mx_i = P[mx_i];
    }
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
	return 0;
}