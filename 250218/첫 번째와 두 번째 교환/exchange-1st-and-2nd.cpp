#include <iostream>
#include <string>

using namespace std;

string s;
char a,b;
int main() {
    cin >> s;
    a = s[0];
    b = s[1];
    for(int i=0;i<s.size();i++){
        if(s[i]==a){
            s[i]=b;
        }
        else if( s[i]==b){
            s[i]=a;
        }
    }
    cout << s;

    return 0;
}