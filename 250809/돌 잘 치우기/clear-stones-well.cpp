#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100];
//bool visited2[100][100];


int mx;

queue<pair<int,int>> q;


void Push(int x, int y){
    q.push(make_pair(x,y));
    visited[x][y] = true;
    //visited2[x][y] = true;
    
}

bool CanGo(int x, int y){
    return (x>=0 && y>=0 && x<n && y<n) && !visited[x][y] && !grid[x][y];
}

//이게 내 딴짓이고 나는 이게 재미있다. 나쁘지 않다. 그냥 하면 되는 거니까 ㅋㅋ
int bfs(int x, int y){

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    // 시작 지점부터 방문한는 수 카운트 push-> 방문
    Push(x,y);
    int cnt=1;


    while(!q.empty()){
        pair<int,int> curr_pos = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_pos.first + dx[i];
            int next_y = curr_pos.second + dy[i];

            if(CanGo(next_x,next_y)){
                Push(next_x,next_y);
                cnt++;
            }
        }
    }
    return cnt;
}

void backtracking(int dol_cnt){
    // 여기서 돌 2개가 선택되면 bfs를 진행하도록 한다.
    if(dol_cnt==m){
        // visited 초기화
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) visited[i][j]=false;

        int temp=0;
        for(int i=0;i<k;i++){
            if(!visited[r[i]][c[i]]){
                temp += bfs(r[i],c[i]);
            }
        }
        mx = max(mx, temp);
        return;
    }
    //이제 그리드를 순회하면서 돌을 치워줘보자
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                backtracking(dol_cnt+1);
                grid[i][j]=1;
            }
        }
    }
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    backtracking(0);
    cout << mx;

    // Please write your code here.

    return 0;
}
