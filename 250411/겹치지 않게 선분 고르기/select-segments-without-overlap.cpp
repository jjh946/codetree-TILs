#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> lines;
bool visited[1000];
int mx;


bool cmp(const pair<int,int>& a,const pair<int,int>& b){
    if (a.first==b.first)
        return a.second < b.second;
    return a.first < b.first; //시작점 부터 비교, 작은걸 넘겨줌
}


void backtrack(int start, int cnt) {

    pair<int,int> cur_line = lines[start];
    for(int i=cur_line.first;i<=cur_line.second;i++){
        if(visited[i]) return;
    }
    for(int i=cur_line.first;i<=cur_line.second;i++){
        visited[i] = true;
        mx = max(mx, cnt);
    }


    for(int s=start+1;s<lines.size();s++){
        pair<int,int> next_line = lines[s];
        
        backtrack(s, cnt+1);
        for(int i=next_line.first;i<=next_line.second;i++){
            if(visited[i]) return;
        }
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        lines.push_back(make_pair(l,r));
    }

    sort(lines.begin(), lines.end(), cmp);

    // for(auto p: lines){
    //     cout << p.first << ' ' << p.second << endl;
    // }
    for(int i=0;i<lines.size();i++){
        for(int j=0;j<1000;j++) visited[j]=false;
        backtrack(i,1);
        
    }

    cout << mx << '\n';


    return 0;
}
