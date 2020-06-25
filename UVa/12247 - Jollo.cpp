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
    freopen("Output.txt","w",stdout);
#endif

    vector<int>cards(53),p1(3),p2(2),vis(3);
    while(cin>>p1[0]>>p1[1]>>p1[2]>>p2[0]>>p2[1]&&p1[0]+p1[1]+p1[2]+p2[0]+p2[1]!=0){

        sort(p1.begin(),p1.end());
        cards.clear();
        cards.resize(53);
        cards[p1[0]]=1,cards[p1[1]]=1,cards[p1[2]]=1,cards[p2[0]]=1,cards[p2[1]]=1;
        int z,cnt;
        for(z=1;z<=52;z++){
            if(cards[z]==1)continue;
            vector<int>temp  = p2;
            temp.push_back(z);
            sort(temp.begin(),temp.end());   
            vis.clear();
            vis.resize(3);
            cnt=0;
            for(int j=0;j<3;j++){
                for(int i=0;i<3;i++){
                    if(vis[i]==0){
                        if(temp[j]<p1[i]){
                            vis[i]=1;
                            cnt++;
                            break;
                        }
                    }
                }
            }
            if(cnt<=1)
                break;
        }
        if(z>52)
            puts("-1");
        else
            cout<<z<<endl;
    } 
    return 0;
}
