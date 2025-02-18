#include <iostream>
#include <string>
using namespace std;

string s;
int q;


int main() { 
    cin >> s >> q;
    for(int i=1;i<=q;i++){
        int c;
        cin >> c;
        if(c==1){
            int a, b;
            cin >> a >> b;
            char tmp = s[a-1];
            s[a-1] = s[b-1];
            s[b-1] = tmp;
            cout << s << '\n';
        }
        else{
            char a, b;
            cin >> a >> b;
            for(int j=0;j<s.size();j++){
                if(s[j]==a){
                    s[j]=b;
                }
            }
            cout << s << '\n';
        }

    }

    return 0;
}