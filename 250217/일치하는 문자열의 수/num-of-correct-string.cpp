#include <iostream>
#include <string>
using namespace std;

int n;
string A;

int main() {
    // Please write your code here.
    cin >> n >> A;

    int cnt = 0;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        if(s==A) cnt++;
    }
    cout << cnt;
    return 0;
}