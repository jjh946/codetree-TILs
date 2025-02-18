#include <iostream>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    
    while(1){
        string s;
        cin >> s;
        if(s=="END") break;
        else{
            for(int i=s.size()-1;i>=0;i--){
                cout << s[i];
            }
            cout << endl;
        }
    }
    return 0;
}