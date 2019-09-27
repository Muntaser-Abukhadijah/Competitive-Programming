// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 998244353;
const int N = 100000 + 7;

int tc,m,t,q,a,b,i,x,n;
char type;
string s,comp;
int seg[5000000];
char lazy[5000000];
void push(int p,int s,int e,char type)
{
    if(lazy[p]!='\0')
    {
        if(type=='F')
        {
            seg[p]=e-s+1;
            if(s!=e)
            {
                lazy[p*2]='F';
                lazy[p*2+1]='F';
            }
        }
        else if(type=='E')
        {
            seg[p]=0;
            if(s!=e)
            {
                lazy[p*2]='E';
                lazy[p*2+1]='E';
            }
        }
        else
        {
            seg[p]=(e-s+1)-seg[p];
            if(s!=e)
            {
                //              lazy[p*2]=(lazy[p*2]=='\0')?'I':(lazy[p*2]=='I')?'\0':(lazy[p*2]=='E')?'F':'E';
                if(lazy[p*2]=='\0')
                    lazy[p*2]='I';
                else if(lazy[p*2]=='I')
                    lazy[p*2]='\0';
                else if(lazy[p*2]=='E')
                    lazy[p*2]='F';
                else if(lazy[p*2]=='F')
                    lazy[p*2]='E';

                if(lazy[p*2+1]=='\0')
                    lazy[p*2+1]='I';
                else if(lazy[p*2+1]=='I')
                    lazy[p*2+1]='\0';
                else if(lazy[p*2+1]=='E')
                    lazy[p*2+1]='F';
                else if(lazy[p*2+1]=='F')
                    lazy[p*2+1]='E';
//                lazy[p*2+1]=(lazy[p*2+1]=='\0')?'I':(lazy[p*2+1]=='I')?'\0':(lazy[p*2+1]=='E')?'F':'E';
            }
        }
        lazy[p]='\0';
    }
}
void build(int p,int s,int e)
{
    if(s==e)
    {
        seg[p]=(comp[s]-'0');
        return ;
    }
    build(p*2,s,(s+e)/2);
    build(p*2+1,(s+e)/2+1,e);
    seg[p]=seg[p*2]+seg[p*2+1];
}
void update(int p,int s,int e,int l,int r,char type)
{
    push(p,s,e,lazy[p]);
    if(s>=l&&e<=r)
    {
        lazy[p]=type;
        push(p,s,e,lazy[p]);
        return;
    }
    if(s>r||e<l)
        return;
    update(p*2,s,(e+s)/2,l,r,type);
    update(p*2+1,(e+s)/2+1,e,l,r,type);
    seg[p]=seg[p*2]+seg[p*2+1];
}
int get(int p,int s,int e,int l,int r)
{
    push(p,s,e,lazy[p]);
    if(s>=l&&e<=r)
        return seg[p];
    if(s>r||e<l)
        return 0;
    return get(p*2,s,(s+e)/2,l,r)+ get(p*2+1,(s+e)/2+1,e,l,r);
}
int main()
{
 //   freopen("output2.txt","w",stdout);
    scanf("%d\n",&tc);
    while(tc--)
    {
        memset(seg,0,sizeof(seg));
        for(int i=0;i<5000000;i++)
            lazy[i]='\0';
        printf("Case %d:\n",++x);
        i=1;
        comp="";
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&t);
            cin>>s;
            for(int i=0; i<t; i++)
                comp+=s;
        }
        n=comp.size();
        build(1,0,n-1);
        scanf("%d",&q);
        while(q--)
        {
            scanf(" %c%d%d",&type,&a,&b);
            if(type=='S')
                printf("Q%d: %d\n",i++,get(1,0,n-1,a,b));
            else
                update(1,0,n-1,a,b,type);
        }
    }
    return 0;
}
