#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    char c;
    getline(cin,str);
    cin >> c;

    int cnt = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]==c) cnt++;
    }
    cout << cnt;

    return 0;
}