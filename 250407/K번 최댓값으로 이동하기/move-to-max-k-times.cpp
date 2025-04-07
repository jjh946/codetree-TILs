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
    
    // 큐 초기화
    while(!q.empty()) q.pop();
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    Push(x,y);
    X = grid[x][y];
    mx = -1; // -1로 초기화하여 아무것도 찾지 못할 경우를 대비

    while(!q.empty()){
        pair<int,int> cur_pos = q.front();
        q.pop();

        int cur_x = cur_pos.first;
        int cur_y = cur_pos.second;

        for(int i=0; i<4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(CanGo(next_x,next_y)) {
                Push(next_x,next_y);
                if(grid[next_x][next_y] > mx) {
                    mx = grid[next_x][next_y];
                }
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

    for(int it=1; it<=k; it++){
        bfs(r,c);
        
        // 갈 수 있는 곳이 없으면
        if(mx == -1) {
            break; // 또는 현재 위치 유지
        }
        
        // 최대값을 갖는 위치 중 행이 가장 작고, 행이 같다면 열이 가장 작은 위치 선택
        int new_r = n+1, new_c = n+1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(grid[i][j] == mx && visited[i][j]) {
                    if (i < new_r || (i == new_r && j < new_c)) {
                        new_r = i;
                        new_c = j;
                    }
                }
            }
        }
        
        // 새로운 위치로 이동
        if(new_r <= n && new_c <= n) {
            r = new_r;
            c = new_c;
        }
    }
    
    cout << r << ' ' << c << '\n';

    return 0;
}