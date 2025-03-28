#include <iostream>
#include <algorithm>
using namespace std;

int n;
int sidejob[16][2];
int mx;
int sum;

void backtrack(int start) {
    
    if(start >= n-1) {
        mx = max(mx, sum);
        return;
    }
    

    for(int i=start;i<n;i++){
        int t = sidejob[i][0];
        int p = sidejob[i][1];

        if (i+t <= n){ // 외주 가능 조건 체크
            sum += p;
            backtrack(i+t);
            sum -= p;
        }
        else{ // 외주 불가능하무로 다음 날로 넘김
            backtrack(i+1);
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> sidejob[i][0] >> sidejob[i][1];
    }
    for(int i=0;i<n;i++){
        sum = sidejob[i][1];
        backtrack(i);
    }
    
    cout << mx << '\n';

    return 0;
}