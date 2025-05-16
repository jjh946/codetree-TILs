#include <iostream>
#include <string>

using namespace std;

//이거 두개를 가지고 변수로 사용하는 함수를 만들면 되는거지
string text;
string pattern;

//부분문자열이 되는지를 확인하는 함수
bool isSubStr(int start_idx){
    int n = (int) text.size();
    int m = (int) pattern.size();

    // 패턴을 매칭시키기에 text 문자열 범위를 초과하게 된다면
    // 부분 문자열이 될 수 없으므로 false를 반환한다.
    if(start_idx + m -1 >= n)
        return false;
    
    for( int j=0; j<m;j++){
        // 하나라도 다르다면, 부분 문자열이 아니므로 false를 반환한다.
        if(text[start_idx + j] != pattern[j])
            return false;
    }

    //전부 일치한다면 부분 문자열이므로 true를 반환한다.
    return true;
}

// 부분 문자열의 위치를 찾아 반환한다.
int FindIndex() {
    int n = (int) text.size();
    for(int i = 0; i<n; i++){
        // i번째를 시작으로 부분 문자열이 된다면, 해당 위치를 반환한다.
        if(isSubStr(i)) return i;
    }

    //없다면, -1을 변환한다.
    return -1;
}


int main() {
    cin >> text;
    cin >> pattern;



    
    cout << FindIndex();
    return 0;
}