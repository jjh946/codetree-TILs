#include <iostream>
using namespace std;

int n, m, k;
long long arr[3000001]; 
long long idxTree[5500000]; //100만이 2^20 이니까 2^21정도는 잡아줘야 한다.
int range[5500000][2];
int l, r;
long long sum =0;
//생각해보니까 우선순위 큐로 풀 문제는 아니다. 안 데이터의 순서가 임의로 바뀌게 ㄷ된다. 
//priority_queue<int> pq;

void CallInd(int idx) {

	if (range[idx][0] >= l && range[idx][1] <= r) {
		sum += idxTree[idx];
	}
	else if (idxTree[idx] != 0) {
		//전위 순회를 계속한다.
		CallInd(2 * idx);
		CallInd(2 * idx + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	//data가 주어지고 바로 인덱스트리를 만들어 주면 된다.
	int T = 0; //이유 없이 배열의 크기를 이용해 높이 t를 구했다.
	long long pow = 1; //2^t
	for (pow; n > pow; pow *= 2) T++;

	for (int i = 1; i <= pow; i++) {
		idxTree[pow + i - 1] = arr[i];
		range[pow + i - 1][0] = i;
		range[pow + i - 1][1] = i;
	}
	for (int i = pow-1; i > 0; i--) {
		int lc = 2 * i;
		int rc = 2 * i + 1;
		idxTree[i] = idxTree[lc] + idxTree[rc];
		range[i][0] = range[lc][0];
		range[i][1] = range[rc][1];
	}


	for (int i = 0; i < m+k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		/*
		cout << a << b << c << endl;
		for (int i = 1; i < pow * 2; i++) {
			if (range[i][0] == 1) cout << '\n';
			cout << idxTree[i] << '(' << range[i][0] << ',' << range[i][1] << ") ";
		}
		cout << endl;
		*/

		if (a == 1) {
			// 리프 b 를 c로 바꾸기
		
			idxTree[pow + b - 1] = c;

			for (int i = pow - 1; i > 0; i--) {
				int lc = 2 * i;
				int rc = 2 * i + 1;
				idxTree[i] = idxTree[lc] + idxTree[rc];
				range[i][0] = range[lc][0];
				range[i][1] = range[rc][1];
			}
			//여기서 트리 값을 바꿔주는데 전역변수가 바뀌지 않는 듯 하다. 왜지?

		}
		else if (a == 2) {
			//b~c 합구하기 -> idxTree에서 올라가는
			sum = 0;
			l = b;
			r = c;

			CallInd(1);

			cout << sum << '\n';
		}
		
		
	}
	
	
	return 0;
}