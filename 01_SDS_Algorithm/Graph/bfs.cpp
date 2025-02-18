#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maze_bfs(int n, int m, vector<vector<int>>&grid){
    int shortest_path_len = -1;
    vector<vector<bool>> visited(n, vector<bool>(m,false));

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    queue<pair<int, pair<int, int>>> q;
    q.push({1,{0,0}});
    visited[0][0] = true;

    while (!q.empty()) {
        int cur_len = q.front().first;
        int cur_r = q.front().second.first;
        int cur_c = q.front().second.second;
        q.pop();
//하다만
    }

}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i=0;i<n;i++){
        string row;
        cin >> row;
        for (int j=0;j<m;j++){
            grid[i][j] = row[j] - '0';
        }
    }
    cout << maze_bfs(n,m,grid) << endl;

    return 0;
}