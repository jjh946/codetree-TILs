#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Write your code here!
    int big;
    int small;
    if (n>m){
        big = n;
        small = m;
    }
    else{
        big = m;
        small = n;
    }
    int i = 2;
    int tmp = big;
    
    while( tmp%small != 0 ){
        tmp = big*i;
        //cout << tmp << ' ';
        i++;
    }
    //cout << endl;
    cout << tmp;
    

    return 0;
}