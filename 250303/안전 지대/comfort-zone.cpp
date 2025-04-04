#include <iostream>
#include <cstring>

using namespace std;

int N, M , k;
int grid[51][51];
bool visited[51][51];


void dfs(int x, int y) {
    visited[x][y] = true;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M){
            if(grid[next_x][next_y]>k && !visited[next_x][next_y]){
                
                dfs(next_x, next_y);
            }
        }
    }
}


int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    //그냥 높이만큼 돌다가 탈출해야지
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            max_height = max(max_height, grid[i][j]);  // 가장 높은 집 찾기
        }
    }

    int K=1, mx=0;
    for (k = 1; k <= max_height; k++) { 
        //dfs를 반복해서 개수를 카운트 하면서 visited를 찍어줌.
        int cnt=0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(grid[i][j]>k && !visited[i][j]){
                    cnt++;
                
                    dfs(i,j);
                }
            }
        }
        //if (cnt == 0) break;
        if(cnt > mx){
            mx = cnt;
            K = k;
        }

    }


    cout << K << ' ' << mx << endl;

    return 0;
}
