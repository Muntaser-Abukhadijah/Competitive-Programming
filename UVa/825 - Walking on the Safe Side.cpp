// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 998244353;
const int N = 100000 + 7;

int tc,w,n,x;
string s;
map<pair<int,int>,int>mp;
int mem[1000][1000];
bool valid(int i,int j)
{
    return i>0&&i<=w&&j>0&&j<=n;
}
int calc(int i,int j)
{
    if(mp.find({i,j})!=mp.end()||!valid(i,j))
        return 0;
    if(i==w&&j==n)
        return 1;
    int &ret=mem[i][j];
    if(ret!=-1)
        return ret;
    return ret=calc(i+1,j)+calc(i,j+1);
}
int main()
{
    //freopen("output2.txt","w",stdout);
    scanf("%d",&tc);
    bool ok=false;
    while(tc--)
    {
        if(ok)
            puts("");
        ok=true;
        memset(mem,-1,sizeof(mem));
        mp.clear();
        scanf("%d%d",&w,&n);
        getline(cin,s);
        for(int i=1; i<=w; i++)
        {
            getline(cin,s);
            istringstream iss(s);
            int j=1;
            while(j)
            {
                iss>>x;
                if(j==1)
                {
                    j++;
                    continue;
                }
                if(!iss)
                    break;
                mp[ {i,x}]=1;
                j++;
            }
        }
        printf("%d\n",calc(1,1));
    }

    return 0;
}
