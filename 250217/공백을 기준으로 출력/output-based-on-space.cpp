#include <iostream>
using namespace std;

string s1,s2;

int main() {
    // Please write your scode here.
    getline(cin,s1);
    getline(cin,s2);

    for(int i=0;i<s1.size();i++){
        if(s1[i]!=' '){
            cout << s1[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]!=' '){
            cout << s2[i];
        }
    }

    return 0;
}