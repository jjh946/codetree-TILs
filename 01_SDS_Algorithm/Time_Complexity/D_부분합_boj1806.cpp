#include <iostream>

using namespace std;

int n, s;
int sequence[100001];

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> sequence[i];

	//연속된 수들이니 투포인터
	int l = 0;
	int r = 0;
	int shortest_len = n+1000;

	//투포닝터로 했으나 시간초과
	int sum = sequence[0];
	while (r < n) {
	
		if (sum >= s) {
			int length = r - l + 1;
			if (length == 1) {
				cout << '1' << endl;
				return 0;
			}
			if (length < shortest_len) {
				shortest_len = length;
			}
			sum -= sequence[l++];   //sum의 변화를 L R을 옯겨 줄 때 마다 해야 한다.
		}
		else {
			sum += sequence[++r]; 
			
		}

	}
	if (shortest_len <= n) {
		cout << shortest_len << endl;
	}
	else cout << '0' << endl;
	


	return 0;
}