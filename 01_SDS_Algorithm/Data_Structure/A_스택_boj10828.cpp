#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n, m;
    stack<int> st;
    string cmd;

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") cin >> m, st.push(m);
        else if (cmd == "pop") cout << (st.empty() ? -1 : (m = st.top(), st.pop(), m)) << '\n';
        else if (cmd == "top") cout << (st.empty() ? -1 : st.top()) << '\n';
        else if (cmd == "size") cout << st.size() << '\n';
        else if (cmd == "empty") cout << (st.empty() ? 1 : 0) << '\n';
    }
    return 0;
}