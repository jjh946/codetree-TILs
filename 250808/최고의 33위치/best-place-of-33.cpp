#include <iostream>

using namespace std;

int N;
int grid[20][20];
int mx;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    
    for (int i = 0; i < N-2; i++) {
        for (int j = 0; j < N-2; j++) {
            int cnt=0;
            for(int x=0;x < 3; x++){
                for(int y=0;y<3;y++){
                    if(grid[i+x][j+y]) cnt++;
                }
            }
            if(cnt>mx) mx = cnt;
        }
    }
    cout << mx;

    // Please write your code here.

    return 0;
}
