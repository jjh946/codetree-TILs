#include <iostream>

using namespace std;

int n, m;
int grid[103][103];
bool visited[103][103];
//int answer[100][100];
int order;

void dfs(int x, int y){
    int dx[2] = {1,0};
    int dy[2] = {0,1};

    for(int i=0;i<2;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x < n && next_y < m && grid[next_x][next_y] && !visited[next_x][next_y]) {
            //answer[next_x][next_y] = order++;
            visited[next_x][next_y] = true;
            dfs(next_x, next_y);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    //answer[0][0] = order++;
    visited[0][0] = true;
    dfs(0,0);

    if(visited[n-1][m-1]){
        cout << 1 << endl;
    }
    else cout << 0 << endl;

    return 0;
}
