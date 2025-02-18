#include <iostream>
#include <algorithm>
//쿠르스칼 알고리즘
//1. 간선정렬
//2. E(a,b)를 볼 때, a와 b가 연결되어었으면 pass
//  그렇지 않다면 union(a,b)
using namespace std;

struct Edge {
	int dist;
	int x, y;
	bool operator < (const Edge a)const { //나중에 정렬을 하는 순간을 위해서 우선순위를 정하는 방법
		return dist < a.dist;  
	}
}edge[100001];

int n, m;
int uni[100001];

int getParent(int x) {
	if (x == uni[x]) return x;
	return uni[x] = getParent(uni[x]);
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> edge[i].x >> edge[i].y >> edge[i].dist;
	}
	for (int i = 1; i <= n; i++)uni[i] = i; //uni?
	sort(edge +1, edge + m +1); //edge들을 가중치대로 오름차순 정렬
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = getParent(edge[i].x);
		int y = getParent(edge[i].y);
		if (x != y) {
			ans += edge[i].dist;
			uni[x] = y;
		}
	}
	cout << ans << endl;

	return 0;
}