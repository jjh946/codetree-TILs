#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    // Please write your code here.
    cin >> s;

    s.erase(1, 1);
    s.erase(s.size()-2,1);

    cout << s;

    return 0;
}