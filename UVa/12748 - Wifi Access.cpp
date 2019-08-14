// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 1000007;

int tc,n,m,x,y,r;
struct edge
{
	int x, y, r;
	edge(int xx=0, int yy=0, int rr=0)
	{
		x = xx;
		y = yy;
		r = rr;
	}
};
vector<edge>pos;
int dist(int x1,int y1,int x2,int y2)
{
    return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    scanf("%d",&tc);
    for(int t=0;t<tc;t++)
    {
        scanf("%d%d",&n,&m);
        pos.clear();
        pos.resize(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&x,&y,&r);
            pos[i]=edge(x,y,r);
        }
        printf("Case %d:\n",t+1);
        while(m--)
        {
            bool ok=true;
            scanf("%d%d",&x,&y);
            for(int i=0; i<n; i++)
            {
                if(dist(pos[i].x,pos[i].y,x,y)<=pos[i].r*pos[i].r)
                {
                    puts("Yes");
                    ok=false;
                    break;
                }
            }
            if(ok)
                puts("No");
        }
    }
    return 0;
}
