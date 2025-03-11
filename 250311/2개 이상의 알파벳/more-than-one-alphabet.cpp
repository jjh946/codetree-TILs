#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string A;
unordered_map<char, int> umap;
//이 문제에서는 set을 사용하는게 맞았겠지만, 연습겸 해시맵을 사용하도록 하였다. 

void func(string a){
    int cnt = 0;

    for(int i=0;i<a.size();i++){
        
        if(umap.find(a[i]) != umap.end()){ //키존제 여부 확인. 없으면 umap.end() 반환
            umap[a[i]]++;
        }
        else{
            umap[a[i]] = 1;
        }
    }

    if(umap.size()>=2){
        cout << "Yes" <<endl;
    }
    else{
        cout << "No" << endl;
    }

}

int main() {
    cin >> A;

    // Please write your code here.
    func(A);
    return 0;
}