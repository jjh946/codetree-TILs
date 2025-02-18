#include <iostream>
using namespace std;

int m, k;
int arr[50];


int main(){
    cin >> m;

    int total = 0;
    for(int i=0;i<m;i++) {
        cin >> arr[i];
        total += arr[i];
    }
    cin >> k;

    double answer = 0;
    for(int i=0;i<m;i++){
        if (arr[i]<k) continue;
        double up = double(arr[i]);
        double down = double(total);
        double prob = 1;
        for(int j=0;j<k;j++){
            prob *= up/down;
            up -= 1;
            down -= 1;
        }
        answer += prob;
    }
    
    cout.precision(10);
    cout << fixed;
    cout << answer << endl;

    return 0;
}
