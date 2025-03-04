#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // 이런 구현에서 딸리는 것이 느껴진다. 
    int ans = 1600000000;
    for (int i = 0; i < N; i++) {
        // i번째 좌표 제외하고 넓이 구하기

        int max_x = 0, max_y = 0, min_x = 40001, min_y = 40001;

        for(int j = 0; j<N; j++){
            if(j==i) continue;
            
            min_x = min(min_x, x[j]);
            min_y = min(min_y, y[j]);
            max_x = max(max_x, x[j]);
            max_y = max(max_y, y[j]);
        }
        ans = min(ans, (max_x-min_x)*(max_y-min_y));
    }

    cout << ans << endl;

    return 0;
}