#include <iostream>
#include <string>

using namespace std;

string A;

bool Palindrome(string str){
    for(int i=0;i<str.size()/2+1;i++){
        if(str[i]!=str[str.size()-i-1]) return false;
    }
    return true;
}

int main() {
    cin >> A;

    // Write your code here!

    if (Palindrome(A)) cout << "Yes";
    else cout << "No";

    return 0;
}