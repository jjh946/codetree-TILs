#include <iostream>

using namespace std;

int n, m, ans;
int grid[106][106];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 1; i <= n; i++){
        int mx = 1;
        for (int j = 1; j <= n; j++){
            if (grid[i][j]==grid[i][j-1]){
                mx++;
            }
            else{
                mx = 1;
            }

        }
        if(mx >= m){
            ans++;
            //cout << i << endl;
        }

    }
    for (int i = 1; i <= n; i++){
        int mx = 1;
        for (int j = 1; j <= n; j++){
            if (grid[j][i]==grid[j-1][i]){
                mx++;
            }
            else{
                mx = 1;
            }

        }
        if(mx >= m){
            ans++;
            //cout << i << endl;
        }

    }
    cout << ans;

    return 0;
}
//집중을 좀 하겠니