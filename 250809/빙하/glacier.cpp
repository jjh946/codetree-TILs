#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_TIME 200

int N, M;
int grid[200][200];
bool visited[100][100];
bool isMelted[100][100];
 
queue<pair<int,int>> q;
queue<pair<int,int>> toMelt;
int lastMeltedCnt;


void Push(int x,int y){
    q.push(make_pair(x,y));
    visited[x][y] = true;
}


bool inRange(int x, int y){
    return (x>=0 && y>=0 && x<N && y<M);
}

bool CanGo(int x, int y){
    return inRange(x,y) && !visited[x][y] && grid[x][y]==0;
}  

bool CanMelt(int x,int y){
    return inRange(x,y) && !isMelted[x][y] && grid[x][y]==1;
}
    

void findToMelt(){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    Push(0,0);
    

    while(!q.empty()){
        pair<int,int> curr_pos = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_pos.first + dx[i];
            int next_y = curr_pos.second + dy[i];

            if(CanMelt(next_x,next_y)){
                toMelt.push(make_pair(next_x,next_y));
                isMelted[next_x][next_y] = true;
            }

            if(CanGo(next_x,next_y)){
                Push(next_x,next_y);
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

    
    for(int time=0;time<MAX_TIME;time++){

        // visited 초기화
        bool isAllMelted = true;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) {
                visited[i][j]=false;
                if(grid[i][j]==1) isAllMelted=false;
            }            
        }

        //bfs 돌려서 toMelt큐 채워주기
        findToMelt();

        //큐가 비어있으면 1없음? 근데 항상 큐가 비어 있는 것 같은데
        if(toMelt.empty()){
            cout << time << ' ' << lastMeltedCnt;
            return 0;
        }
        //cout << "Time: " << time << endl;
        lastMeltedCnt=0;
        while(!toMelt.empty()){
            //일단 여기서 부터 문제가 있다. 
            pair<int,int> meltPoint = toMelt.front();
            toMelt.pop();
            //cout << '(' << meltPoint.first << ',' << meltPoint.second << ") ";

            grid[meltPoint.first][meltPoint.second]=0;
            lastMeltedCnt++;
        }
        //cout << endl;
    }

    return 0;
}
