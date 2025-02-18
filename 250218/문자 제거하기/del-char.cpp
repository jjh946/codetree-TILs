#include <iostream>
#include <string>
using namespace std;

string s;

int main(){
    cin >> s;

    int len = s.length();
    
    while(len > 1 ){
        int i;
        cin >> i;
        if(i>=len){
            i = len-1;
        }
        s.erase(i,1);
        len --;
        cout << s <<'\n';
        
    }
    
    return 0;
}