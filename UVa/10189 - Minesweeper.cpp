#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 100000 + 7;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast() {
    std::ios_base::sync_with_stdio(0);
}

int n,m,it;
vector<vector<char>>grid;
vector<vector<int>>ans;

int dirx[]= {1,-1,0,0,-1,1,1,-1};
int diry[]= {0,0,-1,1,1,1,-1,-1};

bool isValid(int x,int y) {
    return x>-1&&x<n&&y>-1&&y<m&&grid[x][y]!=0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif

    while(cin>>n>>m&&n+m!=0) {
        it++;
        grid.clear();
        ans.clear();
        grid.resize(n,vector<char>(m));
        ans.resize(n,vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>grid[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='*') {
                    for(int k=0; k<8; k++) {
                        int tox= i + dirx[k];
                        int toy= j + diry[k];
                        if(isValid(tox,toy)) {
                            ans[tox][toy]++;
                        }
                    }
                }
            }
        }

        cout<<"Field #"<<it<<":"<<endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='*')
                    cout<<'*';
                else
                    cout<<ans[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
