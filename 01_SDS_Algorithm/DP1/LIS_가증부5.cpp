#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> lis; //가장긴증가하는부분수열 lis를 저장할 벡터
    vector<int> indices(n);
    vector<int> P(n,-1); // 각 원소의 이전 원소의 인덱스를 저장

    for(int i=0;i<n;++i){
        auto pos = lower_bound(lis.begin(), lis.end(), A[i]); //lower_bound까지는 외울만 하다.
        int lis_index = distance(lis.begin(), pos);

        if(pos == lis.end()){
            lis.push_back(A[i]);
        }
        else{
            *pos = A[i];
        }

        indices[i] = lis_index;
        if(lis_index >0){
            P[i] = find(indices.begin(), indices.begin()+i, lis_index-1) - indices.begin();
        }

    }




    int lis_length = lis.size();
    cout << lis_length << '\n';

    stack<int> lis_sequence;
    for (int i = n - 1; i >= 0; --i) {
        if (indices[i] == lis_length - 1) {
            lis_sequence.push(A[i]);
            lis_length--;
        }
    }

    while (!lis_sequence.empty()) {
        cout << lis_sequence.top() << ' ';
        lis_sequence.pop();
    }
    cout << '\n';

    return 0;
}
