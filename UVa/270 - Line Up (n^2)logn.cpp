// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 100000 + 7;

int tc,x,y;
string s;
vector<pair<int,int>>pos;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    cin>>tc;
    cin.ignore();
    getline(cin,s);
    bool flag=false;
    while(tc--)
    {
        if(flag)
            puts("");
        flag=true;
        pos.clear();
        while(getline(cin,s)&&s!="")
        {
            istringstream iss(s);
            while(1)
            {
                iss>>x>>y;
                if(!iss)
                    break;
                pos.push_back({x,y});
            }
        }
        int ans=0;
        for(int i=0; i<pos.size(); i++)
        {
            int same=0,h=0,v=0,mx=0,gcdd=0;
            map<pair<int,int>,int>mp;
            for(int j=i+1; j<pos.size(); j++)
            {
                int num=pos[i].second-pos[j].second;
                int dem=pos[i].first-pos[j].first;
                if(num==0&&dem==0)
                    same++;
                if(num==0)
                    h++;
                else if(dem==0)
                    v++;
                else
                {
                    gcdd=gcd(num,dem);
                    num/=gcdd;
                    dem/=gcdd;
                    if(num<0&&dem<0)
                        num*=-1,dem*=-1;
                    mp[ {num,dem}]++;
                    mx=max(mx,mp[ {num,dem}]);
                }
            }
            ans=max(max(mx+same+1,max(v+same+1,h+same+1)),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
