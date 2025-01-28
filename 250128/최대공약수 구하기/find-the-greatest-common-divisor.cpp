#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Write your code here!
    int i  = 1;
    int answer;
    while(i<=n && i<=m){
        if(n%i==0 && m%i==0){
            answer = i;
        }
        i++;
    }
    cout << answer;


    return 0;
}