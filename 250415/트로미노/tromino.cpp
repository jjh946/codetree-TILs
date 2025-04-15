#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];

int main() {
    cin >> n >> m;

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            int next_x, next_y, next_x2, next_y2;
            for(int k=0;k<4;k++){
                // ㄴ 자 합해보기
                next_x = i+dx[k];
                next_y = j+dy[k];
                next_x2 = i+ dx[(k+1)%4];
                next_y2 = j+ dy[(k+1)%4];

                if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < m){
                    if(next_x2 >= 0 && next_y2 >= 0 && next_x2 < n && next_y2 < m){
                        tmp = grid[i][j] + grid[next_x][next_y] 
                            + grid[next_x2][next_y2];
                        mx = max(mx, tmp);
                    }
                } 

            }
            // ㅣ 자 합해보기
            next_x = i + (-1);
            next_y = j + 0;
            next_x2 = i + 1;
            next_y2 = j + 0;
            if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < m){
                if(next_x2 >= 0 && next_y2 >= 0 && next_x2 < n && next_y2 < m){
                    tmp = grid[i][j] + grid[next_x][next_y] 
                        + grid[next_x2][next_y2];
                    mx = max(mx, tmp);
                }
            } 

            // ㅡ 자 합해보기
            next_x = i + 0;
            next_y = j-1;
            next_x2 = i + 0;
            next_y2 = j+1;
            if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < m){
                if(next_x2 >= 0 && next_y2 >= 0 && next_x2 < n && next_y2 < m){
                    tmp = grid[i][j] + grid[next_x][next_y] 
                        + grid[next_x2][next_y2];
                    mx = max(mx, tmp);
                }
            } 
        }
    }
    cout << mx << endl;


    return 0;
}

