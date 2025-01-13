#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string command[10000];
int A[10000];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> A[i];
        }
    }

    // Write your code here!
    list<int> l;
    for (int i = 0; i < N; i++) {
        string cmd = command[i];
        if (cmd == "push_front"){
            l.push_front(A[i]);
        }
        else if (cmd == "push_back") {
            l.push_back(A[i]);
        }
        else if (cmd == "pop_front") {
            cout << l.front() << endl;
            l.pop_front();
        }
        else if (cmd == "pop_back") {
            cout << l.back() << endl;
            l.pop_back();
        }
        else if (cmd == "size") {
            cout << l.size() << endl;
        }
        else if (cmd == "empty") {
            cout << l.empty() << endl;
        }
        else if (cmd == "front") {
            cout << l.front() << endl;
        }
        else if (cmd == "back") {
            cout << l.back() << endl;
        }
    }

    return 0;
}

