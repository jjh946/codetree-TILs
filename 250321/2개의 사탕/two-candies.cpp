#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

char grid[10][10];


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool r_out, b_out;



int ans = 11;


void move_candy(char candy, int i, int j, int k){
    int cur_x = i + dx[k];
    int cur_y = j + dy[k];
    if(grid[cur_x][cur_y]=='O'){
        if(candy == 'R'){
            r_out = true;
        }
        else if(candy == 'B'){
            b_out = true;
        }
        grid[cur_x - dx[k]][cur_y - dy[k]] = '.';
    }
    while(grid[cur_x][cur_y]=='.' ){
        grid[cur_x][cur_y] = candy;
        grid[cur_x - dx[k]][cur_y - dy[k]] = '.';
        cur_x += dx[k];
        cur_y += dy[k];
        if(grid[cur_x][cur_y]=='O'){
            if(candy == 'R'){
                r_out = true;
            }
            else if(candy == 'B'){
                b_out = true;
            }
            grid[cur_x - dx[k]][cur_y - dy[k]] = '.';
        }
    }
}

void incline_box(int k){
    int rx, ry;
    int bx, by;
    // r b 위치 찾기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='R'){
                rx = i;
                ry = j;
            }
            else if(grid[i][j]=='B'){
                bx = i;
                by = j;
            }
        }
    }
    // 이동 방향의 앞에 있는 것부터 이동
    if(k==0){
        if(rx<=bx){
            move_candy('R',rx,ry,k);
            move_candy('B',bx,by,k);
        }
        else{
            move_candy('B',bx,by,k);
            move_candy('R',rx,ry,k);
        }
    }
    else if(k==1){
        if(rx>=bx){
            move_candy('R',rx,ry,k);
            move_candy('B',bx,by,k);
        }
        else{
            move_candy('B',bx,by,k);
            move_candy('R',rx,ry,k);
        }
    }
    else if(k==2){
        if(ry<=by){
            move_candy('R',rx,ry,k);
            move_candy('B',bx,by,k);
        }
        else{
            move_candy('B',bx,by,k);
            move_candy('R',rx,ry,k);
        }
    }
    else if(k==3){
        if(ry>=by){
            move_candy('B',bx,by,k);
            move_candy('R',rx,ry,k);
        }
        else{
            move_candy('B',bx,by,k);
            move_candy('R',rx,ry,k);
        }
    }
}


void backtrack (int cnt){

    if (b_out)
        return;
    
    if (r_out){
        ans = min(ans,cnt);
        return;
    }

    if(cnt >= 10) {
        return;
    }

    for(int dir=0;dir<4;dir++) {

        char temp[10][10];
        // 원본 그리드는 남겨두고 계속 복사해서 사용
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j] = grid[i][j];
            }
        }
        bool old_r_out = r_out;
        bool old_b_out = b_out;

        incline_box(dir);

        backtrack(cnt+1);   

        //탐색 후 퇴각하여 기울이기 전 상태로 복원, 그 다음 방향도 동일한 기회주기
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=temp[i][j];
            }
        }
        r_out = old_r_out;
        b_out = old_b_out;
    }
}


int main() {
    // Please write your code here.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    //기울이기 함수는 환성했는데 경우의 수를 어떻게 잡을 것인가
    // 모든 경우의 수 다 해보기, 백트레킹?

    backtrack(0);

    if(ans == 11) ans = -1;

    cout << ans << '\n';
    

    return 0;
}


    // incline_box(3);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';



    // incline_box(1);
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    
    // incline_box(2);
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // cout << r_out << '\n' << b_out;