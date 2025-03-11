#include <iostream>

using namespace std;

int n;
int grid[100][100];
int visited[100][100];

int area_cnt, block_cnt, mx;

void dfs(int x, int y){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x >= 0 && next_y >=0 && next_x < n && next_y < n){
            //현재위치와 다음 위치의 숫자가 같다면
            if(grid[next_x][next_y]==grid[x][y] && (!visited[next_x][next_y])){
                visited[next_x][next_y] = true;
                area_cnt++;
                dfs(next_x,next_y);
            }
        }
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if(!visited[i][j]){
                area_cnt = 0;
                dfs(i,j);
                if(area_cnt>=4){
                    block_cnt++;
                }
                
                if(area_cnt > mx){
                    mx = area_cnt;
                }
            }
        }
    }

    cout << block_cnt << ' ' << mx << endl;

    return 0;
}
