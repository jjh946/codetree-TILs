#include <iostream>
#include <algorithm>

using namespace std;


int n, m;
int trees[1000001];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> trees[i];

	//  sort 내림차순에는 greater<>() 세번째 조건을 쓸 수 있다. 만약 조건을 주고 싶다면 compare 를 사용할 수 있다. 
	sort(trees, trees + n, greater<>());

	int l, r, mid, last_p; // h를 구하는 것을 미드 값을 주고 바이너리 서치로 간다.
	l = 0;
	r = trees[0];
	
	while (l <= r) {
		mid = (l + r) / 2;
		//탈출 조건: 잘라서 합치면 
		long long sum = 0; // 이거 5억짜리 나무 100만개가 있으면 당연히 넘는다. 최악의 캐이스 무조건 고려하자.
		for (int i = 0; i < n; i++) {
			if (trees[i] >  mid) {
				sum += trees[i] - mid;
				//cout << sum << endl;
			}
			else break;
		}
		if (sum == m) {
			cout << mid << endl;
			//cout << "haha good!";
			return 0;
		}
		if (sum > m) {
			last_p = mid;
			l = mid + 1;
		}
		else if (sum<m) {
			r = mid - 1;
		}
	}
	cout << last_p << endl;
	

	return 0;
}