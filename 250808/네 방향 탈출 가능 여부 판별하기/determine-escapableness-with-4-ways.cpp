#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int n,m;
int grid[100][100];
bool visited[100][100];

queue<pair<int,int>> q;

void Push(int x, int y) {
    visited[x][y] = true;
    q.push(make_pair(x,y));
}

bool CanGo(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m) && !visited[x][y] && grid[x][y];
}


void bfs() {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    Push(0,0);

    while(!q.empty()){  //큐가 끝날 때 까지 반복문 돌려주기 
        pair<int,int> curr_pos = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_pos.first + dx[i];
            int next_y = curr_pos.second + dy[i];

            if(CanGo(next_x,next_y)){
                Push(next_x,next_y);
            }

        }
    }




}



int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    bfs();
    if(visited[n-1][m-1]) cout << 1;
    else cout << 0;
    


    return 0;
}