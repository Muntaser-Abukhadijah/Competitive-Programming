// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 100000 + 7;
//10:59
int n,m,x,y,t=1,child;
vector<vector<int>>adjl;
vector<int>timer,lev,art;
vector<pair<int,int>>bridge;
void dfs(int u,int p)
{
    timer[u]=lev[u]=t++;
    for(int i=0; i<adjl[u].size(); i++)
    {
        if(!timer[adjl[u][i]])
        {
            if(p==-1)
                child++;
            dfs(adjl[u][i],u);
            lev[u] =min(lev[u],lev[adjl[u][i]]);
            if(timer[u]<=lev[adjl[u][i]])
                art[u]=1;
            if(timer[u]<lev[adjl[u][i]])
                bridge.push_back({u,adjl[u][i]});
        }
        else if(adjl[u][i]!=p)
            lev[u]=min(lev[u],timer[adjl[u][i]]);
    }
}
int main()
{
    cin>>n>>m;
    adjl.resize(n);
    timer.resize(n);
    lev.resize(n);
    art.resize(n);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        x--,y--;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    dfs(0,-1);
    art[0]=child>1;
    for(int i=0; i<art.size(); i++)
        if(art[i])
            cout<<i+1<<" ";
    cout<<endl;
    for(int i=0; i<bridge.size(); i++)
        cout<<bridge[i].first+1<<" , "<<bridge[i].second+1<<"\n";
    return 0;
}
