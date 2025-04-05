#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];

int order;
queue<pair<int, int>> q;

// 내가 구현해야 하는 것:
// visited, queue, 

// 보지 말고 일단 구현을 해보고 생각해야 한다. 그래야 머리에 새겨지지.
void Push(int x, int y) {
    visited[x][y] = true;
    q.push(make_pair(x,y));
}

bool CanGo(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m) && !visited[x][y] && grid[x][y];
}


void bfs() {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    Push(0,0);

    while(!q.empty()){
        // 여기가 살짝 다르지만 front pop 둘 다 해줘야 한다는 것을 유의한다. 
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;
        for(int i = 0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(CanGo(new_x, new_y)){
                Push(new_x, new_y);
            }
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

    bfs();
    if(visited[n-1][m-1]) cout << 1 << '\n';
    else cout << 0 << '\n';

    
    return 0;
}
