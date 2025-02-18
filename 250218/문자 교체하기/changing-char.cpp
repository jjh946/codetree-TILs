#include <iostream>
#include <string>
using namespace std;

string s1, s2;

int main() {
    // Please write your code here.
    cin >> s1 >> s2;
    s2[0] = s1[0];
    s2[1] = s1[1];

    cout << s2;

    return 0;
}