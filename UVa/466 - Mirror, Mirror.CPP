// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 998244353;
const int N = 100000 + 7;

int n,pat=1;
vector<vector<char>>ori,tr;

bool comp(vector<vector<char>>temp)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(temp[i][j]!=tr[i][j])
                return false;
    return true;
}
bool rot(vector<vector<char>>&toRot)
{
    vector<vector<char>>temp(n,vector<char>(n));
    for(int i=n-1,ii=0; i>-1&&ii<n; i--,ii++)
        for(int j=0,jj=0; j<n&&jj<n; j++,jj++)
            temp[jj][ii]=toRot[i][j];
    toRot=temp;
    return comp(toRot);
}

bool reflect(vector<vector<char>>&ori)
{
    int mid=n/2;
    for(int i=0; i<mid; i++)
        for(int j=0; j<n; j++)
            swap(ori[i][j],ori[n-i-1][j]);
    return comp(ori);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ori.clear();
        tr.clear();
        ori.resize(n,vector<char>(n));
        tr.resize(n,vector<char>(n));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf(" %c",&ori[i][j]);
            for(int j=0; j<n; j++)
                scanf(" %c",&tr[i][j]);
        }

        if(comp(ori))
            printf("Pattern %d was preserved.\n",pat++);
        else if(rot(ori))
            printf("Pattern %d was rotated %d degrees.\n",pat++,90);
        else if(rot(ori))
            printf("Pattern %d was rotated %d degrees.\n",pat++,180);
        else if(rot(ori))
            printf("Pattern %d was rotated %d degrees.\n",pat++,270);
        else if(rot(ori))
            printf("Pattern %d was rotated %d degrees.\n",pat++,270);
        else if(reflect(ori))
            printf("Pattern %d was reflected vertically.\n",pat++);
        else if(rot(ori))
            printf("Pattern %d was reflected vertically and rotated %d degrees.\n",pat++,90);
        else if(rot(ori))
            printf("Pattern %d was reflected vertically and rotated %d degrees.\n",pat++,180);
        else if(rot(ori))
            printf("Pattern %d was reflected vertically and rotated %d degrees.\n",pat++,270);
        else
            printf("Pattern %d was improperly transformed.\n",pat++);
    }
    return 0;
}
