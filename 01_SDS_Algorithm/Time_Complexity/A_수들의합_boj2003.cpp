#include <iostream>

using namespace std;


int n, m;
int A[10001];


int main() {
	//여기서 띄어쓰기로 N M이 들어오는 것을 구현한다. 
	cin >> n >> m; //아나 그냥 cin이었네 ㅋㅋ
	for (int i = 0; i < n; i++) cin >> A[i];
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		// int의 범위는 20억. 3억은 범위를 넘지 않는다.
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			if (sum == m) {
				
				cnt++;
				//break;
			}
		}
	}
	cout << cnt;


	return 0;
}