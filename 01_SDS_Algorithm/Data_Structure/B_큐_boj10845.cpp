#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    queue<int> q;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int arg;
            cin >> arg;
            q.push(arg);
        } 
        else if (cmd == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } 
        else if (cmd == "size") {
            cout << q.size() << '\n';
        } 
        else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } 
        else if (cmd == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } 
        else if (cmd == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}
