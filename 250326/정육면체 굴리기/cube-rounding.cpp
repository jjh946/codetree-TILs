#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y, k;
int grid[20][20];
int dice[7];

//grid move
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
//position code
int pc[5][7] = { 
    {0,0,0,0,0,0,0},
    {0,4,2,1,6,5,3},
    {0,3,2,6,1,5,4},
    {0,2,6,3,4,1,5},
    {0,5,1,3,4,6,2}
};


void rollthedice(int cmd){
    int cur_x = x + dx[cmd];
    int cur_y = y + dy[cmd];

    //이번 시도 위치가 범위내에 있으면 가고 벗어나면 무시
    if(cur_x>=0 && cur_y>=0 && cur_x<n && cur_y<m){
        //위치 옮겨주기
        x = cur_x;
        y = cur_y;

        //주사위 돌려주기
        int new_dice[7];
        for (int i=1;i<=7;i++){
            new_dice[i] = dice[pc[cmd][i]];
        }

        if(grid[x][y]==0){
            grid[x][y] = new_dice[6];
        }
        else{
            new_dice[6] = grid[x][y];
            grid[x][y] = 0;
        }


        //굴리기 시도 후 상단 면 출력
        cout << new_dice[1] << '\n';

        for (int i=1;i<=7;i++){
            dice[i] = new_dice[i];
        }

    }
    

}


int main() {
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i=0;i<k;i++){
        int cmd;
        cin >> cmd;
        //여기 부터 입력에 따라 주사위를 굴리면 될 것 같다. 
        rollthedice(cmd);
    }
    return 0;
}
