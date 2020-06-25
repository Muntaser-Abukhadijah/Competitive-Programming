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

int n,cnt;
string s1,s2;
vector<int>freq(26);
vector<bool>vis(26);
set<int>st;
int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif

    while(cin>>n&&n!=-1) {
        cin>>s1>>s2;
        cnt=0;
        freq.clear();
        freq.resize(26);
        vis.clear();
        vis.resize(26);
        st.clear();
        for(int i=0; i<s1.size(); i++) {
            if(freq[s1[i]-'a']==0)
                cnt++;
            freq[s1[i]-'a']++;
        }
        for(int i=0; i<s2.size(); i++) {
            if(freq[s2[i]-'a']>0&&!vis[s2[i]-'a']) {
                vis[s2[i]-'a']=1;
                cnt--;
            } else {
                st.insert(s2[i]-'a');
            }
            if(!cnt) {
                cout<<"Round "<<n<<endl<<"You win."<<endl;
                break;
            }
            else if(st.size()>=7) {
                cout<<"Round "<<n<<endl<<"You lose."<<endl;
                break;
            } else if(i+1==s2.size()) {
                cout<<"Round "<<n<<endl<<"You chickened out."<<endl;
                break;
            }
        }
    }

    return 0;
}
