#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin >> s;
    s[1] = 'a';
    s[s.size()-2] = 'a';

    cout << s;


    return 0;
}