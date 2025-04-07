#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int grid[101][101];
int r, c;

bool visited[101][101];
queue<pair<int,int>> q;
int X;
int mx;

bool keepSearch = true;



void Push(int x, int y){
    visited[x][y] = true;
    q.push(make_pair(x,y));
}

bool CanGo(int x, int y){
    return (x>0 && y>0 && x<=n && y<=n) && !visited[x][y] && (grid[x][y]<X);
}

void bfs(int x, int y){
    // 방문 배열 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = false;
        }
    }
    
    // 큐 초기화 (이전 BFS에서 남은 요소들 제거)
    while(!q.empty()) q.pop();

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    Push(x,y);
    X = grid[x][y];
    mx = 0;

    while(!q.empty()){
        pair<int,int> cur_pos = q.front();
        q.pop();

        int cur_x = cur_pos.first;
        int cur_y = cur_pos.second;

        for(int i=0;i<4;i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(CanGo(next_x,next_y)) {
                Push(next_x,next_y);
                mx = max(mx, grid[next_x][next_y]);
            }
        }
    }
    

}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    
    for(int it=1;it<=k;it++){
        bfs(r,c);

        if(mx == 0) break;

        bool found = false;
        for (int i = 1; i <= n && !found; i++) {
            for (int j = 1; j <= n && !found; j++) {
                if(grid[i][j]==mx && keepSearch){
                    r = i;
                    c = j;
                    found = true;
                }
            }
        }
    }
    cout << r << ' ' << c << '\n';


    return 0;
}
