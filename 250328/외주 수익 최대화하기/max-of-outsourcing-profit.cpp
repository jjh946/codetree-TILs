#include <iostream>
#include <vector>
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
        sum += sidejob[i + sidejob[i][0]][1];
        backtrack(i + sidejob[i][0]);
        sum -= sidejob[i + sidejob[i][0]][1];
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