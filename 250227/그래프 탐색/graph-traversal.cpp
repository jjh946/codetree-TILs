#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int cnt = 0;

void dfs(int node) {
    for (int next : graph[node]) {
        if (!visited[next]) {
            visited[next] = true;
            cnt++;
            dfs(next);
        }
    }
}


int main() {
    cin >> n >> m;

    graph.resize(n+1); // 벡터는 리사이즈를 해줘야 함
    visited.resize(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // dfs
    visited[1] = true;
    dfs(1);

    cout << cnt << endl;

    return 0;
}
