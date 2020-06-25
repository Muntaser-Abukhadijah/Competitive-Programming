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
void fast()
{
    std::ios_base::sync_with_stdio(0);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif

    int tc;
    cin>>tc;
    int removed=0;
    int ptr=27,y=0;
    for(int j=1;j<=tc;j++){
        vector<string>cards(52);
        for(string &i:cards)cin>>i;
        ptr=26,y=0,removed=0;
        for(int i=0;i<3;i++){
          
            int val=cards[ptr][0]>='2'&&cards[ptr][0]<='9'?cards[ptr][0]-'0':10;
            y+=val;
            ptr--;
            ptr-=(10-val);
            removed+=((10-val)+1);
        }
        cout<<"Case "<<j<<": "<<((y-1)<=ptr?cards[y-1]:cards[y+removed-1])<<endl;
    }

    return 0;
}
