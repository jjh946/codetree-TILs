#include <iostream>
#include <vector>
using namespace std;
// 그래프를 입력받음.
// 1번노드를 루트로 하는 트리를 구성
// 구성하면서, 각 노드의 깊이와, parent를 구한다.
// 2^k 조상을 미리 구해놓는

int n, m;
vector<int> graph[100001];
int parents[18][100001]; //10만일 경우 2^17
int depths[100001];

//사이클이 없기 때문에 bfs가 아닌 dfs를 쓰는 것이다.
void dfs(int node, int parent, int depth){
	depths[node] = depth;
	parents[0][node] = parent;

	for (int next : graph[node]) {
		if (next == parent) continue;
		dfs(next, node, depth + 1);
	}
}

// 최저공통조상을 구하는 로직
// 1. a,b를 입력받음
// 2. a와 b의 높이를 맞춰준다
// 둘의 최저 공총조상을 logn으로 찾는다.
int getLCA(int a, int b) {

	//a b 크기 정렬을 해준다.
	if (depths[a] < depths[b]) {
		swap(a, b);
	}

	for (int k = 17; k >= 0; k--) {
		if (depths[a] - depths[b] >= (1<<k)) {
			a = parents[k][a];
		}
	}
	if (a == b) return a;

	for (int k = 17; k >= 0; k--) {
		if (parents[k][a] != parents[k][b]) { //@@ 같지 않을 때만 이동
			a = parents[k][a];
			b = parents[k][b];
		}
	}
	return parents[0][a];

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);


	cin >> n;
	// 먼저 무순서 그래프 생성.
	for (int i = 1; i < n; i++) { 
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 1번 노드부터 시작해서 각 노드의 깊이와 부모 구하기. 왜인지는 모르지만 일단 따라가기
	// 지금 예제가 뒤집혀서 들어간다면 입력받으면서 구현은 안될 것.
	dfs(1, 0, 0);

	for (int k = 1; k <= 17; k++) {
		for (int node=1; node <= n; node++) {
            if (parents[k-1][node] != 0){ // @@올바른 부모노드가 있는 경우만
                parents[k][node] = parents[k - 1][parents[k - 1][node]];
            }

		}
	}


	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << getLCA(a, b) << '\n';

	}

	return 0;
}
