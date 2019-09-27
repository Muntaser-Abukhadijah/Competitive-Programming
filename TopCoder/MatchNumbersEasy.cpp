#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int>mat;
string mem[19][55];
string calc(int ind,int rem)
{
    if(ind==mat.size()||rem<=0)
        return "";
    string &ret=mem[ind][rem];
    if(ret.size()!=0)
        return ret;
    string s1=calc(ind+1,rem);
    string s2="";
    if(mat[ind]<=rem)
        s2=to_string(ind)+calc(ind,rem-mat[ind]);
    sort(s2.rbegin(),s2.rend());
    if(s2[0]=='0')s2="0";
    if(s1.size()>s2.size())
        return ret=s1;
    else if(s1.size()<s2.size())
        return ret=s2;
    else
        return ret=max(s1,s2);
}
class MatchNumbersEasy
{
public:
    string maxNumber(vector <int> matches, int n)
    {
        mat=matches;
        return calc(0,n);
    }
};

int main()
{
    MatchNumbersEasy o;
    cout<<o.maxNumber({5, 23, 24}, 30)<<endl;
}

