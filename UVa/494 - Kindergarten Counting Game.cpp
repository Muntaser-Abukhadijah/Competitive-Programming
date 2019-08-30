// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 100000 + 7;

int main()
{
   // freopen("output2.txt","w",stdout);
    string s;
    while(getline(cin,s))
    {
        int cnt=0;
        istringstream iss(s);
        string temp;
        while(1)
        {
            bool ok=true;
            iss>>temp;
            if(!iss)
                break;
            for(int i=0; i<temp.size(); i++)
                if((temp[i]>='a'&&temp[i]<='z')||(temp[i]>='A'&&temp[i]<='Z'))
                {
                    cnt+=ok;
                    ok=false;
                }
                else ok=true;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
