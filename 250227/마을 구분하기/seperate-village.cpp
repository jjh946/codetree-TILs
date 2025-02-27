#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int grid[25][25];
bool visited[25][25];
vector<int> nums;
int cnt , num;


void dfs(int x, int y){
    num++;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < n && next_y < n && grid[next_x][next_y] && !visited[next_x][next_y]){
            visited[next_x][next_y] = true;
            dfs(next_x,next_y);
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
            if(!visited[i][j] && grid[i][j]){
                visited[i][j] = true;
                dfs(i,j);
                nums.push_back(num);
                num = 0;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    sort(nums.begin(), nums.end());
    for( int x : nums){
        cout << x << endl;
    }


    return 0;
}
