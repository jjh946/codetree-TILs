#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    // Please write your code here.
    cin >> s;
    char a, b;
    a=s[0];
    b=s[1];
    for(int i=0;i<s.size();i++){
        if(s[i]==b){
            s[i]=a;
        }
    }
    cout << s;

    return 0;
}