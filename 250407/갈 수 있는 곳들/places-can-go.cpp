#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int grid[101][101];
int r[10000], c[10000];
bool visited[101][101];
int ans;

queue<pair<int,int>> q;


void Push(int x, int y){
    ans++;
    visited[x][y] = true;
    q.push(make_pair(x,y));
}
bool CanGo(int x, int y){
    return (x>0 && y >0 && x<=n && y<=n) && !visited[x][y] && !grid[x][y];
}

void bfs(int x, int y){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    Push(x,y);

    while(!q.empty()){
        pair<int, int> curr_pos = q.front();
        q.pop();

        int curr_x = curr_pos.first;
        int curr_y = curr_pos.second;
        for(int i=0;i<4;i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(CanGo(next_x,next_y)) Push(next_x,next_y);
        }
        
    }


}


int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    // Please write your code here.
    for (int i = 0; i < k; i++){
        if(CanGo(r[i],c[i])) 
            bfs(r[i],c[i]);
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++) cout << visited[i][j];
    //     cout << '\n';
    // }
        

    cout << ans << '\n';

    return 0;
}
