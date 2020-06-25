#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 100000 + 7;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
    std::ios_base::sync_with_stdio(0);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif
    double h, u, d, f;
    while (scanf("%lf%lf%lf%lf", &h, &u, &d, &f)&&h!=0)
    {
        double initH=u,distC=u,hiAfterC=u,hiAfterS=u-d,per=f/100.0*u,cnt=1;
        while(1){
            if(hiAfterS<0||hiAfterC>h)break;
            cnt++;
            initH=hiAfterS;
            distC=distC-per;
            hiAfterC=initH+max(0.0,distC);
            hiAfterS=hiAfterC-d;      
        } 
        if(hiAfterS<0)
            cout<<"failure on day "<<cnt<<endl;
        else
            cout<<"success on day "<<cnt<<endl;
    }
    return 0;
}
