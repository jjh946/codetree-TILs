#include <iostream>
#include <string>
#include <list>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    list<char> l;   // 문자를 관리한 빈 리스트 선언
    list<char>::iterator it;

    for (int i = 0; i < n; i++) {  
        l.push_back(s[i]);   //스트링 전부 링크드 리스트로 넣어주기
    }
    // for (it = l.begin() ; it != l.end(); it++) { // 'd' 'b' 'c'
    //     cout << *it ;
    // }
    it = l.end();
    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        
        //여기다 코드를 짜야 할 것 같다
        

        if (command == 'L') {
            if (it != l.begin())
                it--;
        }
        else if (command == 'R') {
            if (it != l.end())
                it++;
        }
        else if (command == 'D') {
            if (it != l.end()){
                it = l.erase(it);
            }
        }
        else if (command == 'P') {
            char c;
            cin >> c;
            l.insert(it, c);
        }


    }

    // Write your code here!
    //list에 들어있는 원소 값을 순서대로 출력
    for (it = l.begin() ; it != l.end(); it++) { // 'd' 'b' 'c'
        cout << *it ;
    }
    

    return 0;
}
