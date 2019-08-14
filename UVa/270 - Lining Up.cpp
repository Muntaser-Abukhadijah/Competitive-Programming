// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 100000 + 7;

#define crossP(a,b)				  ((conj(a)*b).imag())		           // Cross Product.
#define point                      complex<double>

bool isCollinear(complex<double>a, complex<double>b, complex<double>c)
{
    return (fabs(crossP((b - a), (c - a))) < EPS);           // is point c on line AB.
}

int main()
{
    int tc;
    double x,y;
    string s;
    cin>>tc;
    cin.ignore();
    getline(cin,s);
    bool flag=false;
    while(tc--)
    {
        if(flag)
            puts("");
        flag=true;
        vector<pair<double,double>>pos;
        while(getline(cin,s)&&s.size()>0)
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
        int ans=0,mx=0;
        for(int i=0; i<pos.size(); i++)
        {
            for(int j=i+1; j<pos.size(); j++)
            {
                mx=2;
                for(int k=j+1; k<pos.size(); k++)
                {
                    if(isCollinear(point(pos[i].first,pos[i].second),point(pos[j].first,pos[j].second),point(pos[k].first,pos[k].second)))
                        mx++;
                }
                ans=max(mx,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
