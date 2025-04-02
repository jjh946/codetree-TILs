#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,m;
int grid[200][200];
int mx;

const vector<vector<vector<int>>> blocks = {
    // ㅡ ㅣ 
    {{1,1,1,1}},
    {
        {1},
        {1},
        {1},
        {1},
    },
    // ㅁ
    {
        {1,1},
        {1,1}
    },
    // ㄴ
    {
        {1,0},
        {1,0},
        {1,1}
    },
    {
        {0,1},
        {0,1},
        {1,1}
    },
    {
        {1,1},
        {0,1},
        {0,1}
    },
    {
        {1,1},
        {1,0},
        {1,0}
    },
    {
        {1,1,1},
        {1,0,0}
    },
    {
        {1,1,1},
        {0,0,1}
    },
    {
        {0,0,1},
        {1,1,1}
    },
    {
        {1,0,0},
        {1,1,1}
    },
    // z
    {
        {1,0},
        {1,1},
        {0,1}
    },
    {
        {0,1},
        {1,1},
        {1,0}
    },
    {
        {1,1,0},
        {0,1,1}
    },
    {
        {0,1,1},
        {1,1,0}
    },
    // ㅏ
    {
        {1,0},
        {1,1},
        {1,0}
    },
    {
        {0,1},
        {1,1},
        {0,1}
    },
    {
        {0,1,0},
        {1,1,1}
    },
    {
        {1,1,1},
        {0,1,0}
    }
};


void check_mask(int x,int y,const vector<vector<int>>& mask){
    int h = mask.size();
    int w = mask[0].size();

    int sum = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if (mask[i][j]){
                sum += grid[x+i][y+j];
            }
        }
    }
    mx = max(mx,sum);

}

void move_block(const vector<vector<int>>& mask){
    int h = mask.size();
    int w = mask[0].size();
    for(int i=0;i<=n-h;i++){
        for(int j=0;j<=m-w;j++){
            check_mask(i,j,mask);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(const auto& block : blocks){
        move_block(block);
    }
    cout << mx << '\n';


    return 0;
}