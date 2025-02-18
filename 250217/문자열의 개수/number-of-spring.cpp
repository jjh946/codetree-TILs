#include <iostream>
#include <string>
using namespace std;

string s[200];

int main() {
    // Please write your code here.
    int cnt = 0;
    while(1){
        string str;
        cin >> str;
        if(str=="0") break;
        s[cnt] = str;
        cnt++;
    }
    cout << cnt <<endl;
    for(int i = 0; i < cnt; i += 2)
		cout << s[i] << endl;

    return 0;
}