// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
const ll MOD = 1000000007;
const int N = 1000007;

bitset<1000009>bs;
int x;
vector<int>cs(N);
void sieve()
{
    bs[0]=bs[1]=0;
    for(int i=4;i<N;i+=2)
        bs[i]=0;
    for(int i=3;i*i<N;i+=2)
        if(bs[i])
            for(int j=i*i;j<N;j+=(i+i))
                bs[j]=0;
}
int fact(int n)
{
    int cnt=0;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
    }
    if(n!=1)
        cnt++;
    return cnt;
}
int main()
{
    bs.set();
    sieve();
    for(int i=2;i<N;i++)
    {
        if(bs[i])
            cs[i]=cs[i-1]+1;
        else
            cs[i]=cs[i-1]+fact(i);
    }
    while(scanf("%d",&x)!=EOF)
        printf("%d\n",cs[x]);
    return 0;
}
