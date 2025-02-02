#include <iostream>

using namespace std;

int a;
int c;
char o;

int Plus(int a,int c) {
    cout << a << " + " << c << " = " << a+c;
    return 0;
}
int Minus(int a,int c) {
    cout << a << " - " << c << " = " << a-c;
    return 0;
}
int Divide(int a, int c) {
    cout << a << " / " << c << " = " << a/c;
    return 0;
}
int Multiple(int a,int c) {
    cout << a << " * " << c << " = " << a*c;
    return 0;
}


int main() {
    cin >> a >> o >> c;

    // Write your code here!
    if (o=='+') Plus(a,c);
    else if (o=='-') Minus(a,c);
    else if (o=='/') Divide(a,c);
    else if (o=='*') Multiple(a,c);
    else cout << "False";
    

    return 0;
}