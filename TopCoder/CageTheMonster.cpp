// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 998244353;
const int N = 100000 + 7;

vector<string>grid;
int vis[42][42];
vector<int>block(4);
int temp=1e9;
int dirx[]= {-1,0,1,0};
int diry[]= {0,1,0,-1};
bool vaild(int i,int j)
{
    return i>-1&&i<grid.size()&&j>-1&&j<grid[0].size()&&grid[i][j]!='#';
}
bool dfs(int i,int j)
{
    vis[i][j]=1;
    bool state=true;
    for(int k=0; k<4; k++)
    {
        if((k==0&&block[k])||(k==1&&block[k])||(k==2&&block[k])||(k==3&&block[k]))
            continue;
        int tox=i+dirx[k];
        int toy=j+diry[k];
        if(vaild(tox,toy)&&!vis[tox][toy])
        {
            if(tox==0||tox==grid.size()-1||toy==0||toy==grid[0].size()-1)
                return false;
            state&=dfs(tox,toy);
        }
    }
    return state;
}
int backtrack(int i,int j,int cnt)
{
    memset(vis,0,sizeof(vis));
    bool flag = dfs(i,j);
    if(flag)
        return (temp=min(cnt,temp));
    for(int k=0; k<4; k++)
    {
        if(block[k]==0)
        {
            block[k]=1;
            backtrack(i,j,cnt+1);
            block[k]=0;
        }
    }
    return temp;
}
class CageTheMonster
{
public:
    int capture(vector <string> labyrinth)
    {
        grid=labyrinth;
        int mi=1e9;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++)
                if(grid[i][j]=='^'&&i!=0&&i!=grid.size()-1&&j!=0&&j!=grid[i].size()-1)
                {
                    temp=1e9;
                    memset(vis,0,sizeof(vis));
                    int x= mi,  y =backtrack(i,j,0);
                    mi=min(x,y);
                }
        return mi==1e9?-1:mi;
    }
};

int main()
{
    CageTheMonster o;
    cout<<o.capture(
{
".######..",
".#^^^^#..",
".#^^^^#..",
".#^^^^#..",
".##^^##..",
"...^^...."})<<endl;

    return 0;
}
