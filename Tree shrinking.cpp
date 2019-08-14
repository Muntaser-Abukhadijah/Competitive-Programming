// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 100000 + 7;

vector<vector<int>>adjl;
string getCanForm(int u,vector<vector<string>>&subCan)
{
    string s="(";
    sort(subCan[u].begin(),subCan[u].end());
    for(int i=0; i<subCan[u].size(); i++)
        s+=subCan[u][i];
    s+=")";
    return s;
}
string tree_shrinking()
{
    int n=adjl.size();
    int remNode=n;
    vector<int>deg(n,-1);
    queue<int>leafNode;
    for(int i=0; i<n; i++)
    {
        if(adjl[i].size()<=1)
            leafNode.push(i);
        else
            deg[i]=adjl[i].size();
    }
    vector<vector<string>>subCan(n);
    while(remNode>2)
    {
        int sz=leafNode.size();
        while(sz--)
        {
            int v=leafNode.front();
            leafNode.pop();
            string nodRep=getCanForm(v,subCan);
            for(int i=0; i<adjl[v].size(); i++)
            {
                subCan[v].push_back(nodRep);
                if(--deg[adjl[v][i]]==1)
                    leafNode.push(v);
            }
            remNode--;
        }
    }
    int v1=leafNode.front();
    leafNode.pop();
    int v2=leafNode.empty()?-1:leafNode.front();
    string str1=getCanForm(v1,subCan);
    string str2=v2==-1?"":getCanForm(v2,subCan);
    if(v2==-1)
        return str1;
    subCan[v1].push_back(str2);
    subCan[v2].push_back(str1);
    return min(getCanForm(v1,subCan),getCanForm(v2,subCan));
}
int main()
{
    int n,x,y;
    cin>>n;
    adjl.resize(n);
    for(int i=0; i<n-1; i++)
    {
        cin>>x>>y;
        x--,y--;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    string s1=tree_shrinking();
    adjl.clear();
    adjl.resize(n);
    for(int i=0; i<n-1; i++)
    {
        cin>>x>>y;
        x--,y--;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    string s2=tree_shrinking();
    if(s1==s2)
        puts("YES");
    else
        puts("NO");
    return 0;
}
