#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1,str2,str3;

int main() {
    // Please write your code here.
    cin >> str1 >> str2 >> str3;


    int a,b,c;
    a=str1.length();
    b=str2.length();
    c=str3.length();

    int mx,mn;
    mn = min(a,min(b,c));
    mx = max(a,max(b,c));

    cout << mx-mn;

    return 0;
}