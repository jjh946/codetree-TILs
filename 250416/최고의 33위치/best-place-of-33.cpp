#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[21][21];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Write your code here!
    int mx = 0;
    for(int i=1;i<=N-2;i++){
        for(int j=1;j<=N-2;j++){
            int tmp = 0;
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    if(grid[i+x][j+y]) tmp++;
                }
            }
            mx = max(mx,tmp);
        }
    }
    cout << mx;


    return 0;
}

