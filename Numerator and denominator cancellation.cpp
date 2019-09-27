vector<int>num,dem;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
ll perm()
{
    for(int i=0;i<dem.size();i++)
    {
        for(int j=0;j<num.size();j++)
        {
            if(dem[i]==1)break;
            int gcdd=gcd(num[j],dem[i]);
            num[j]/=gcdd;
            dem[i]/=gcdd;
        }
    }
    ll res=1;
    for(int i=0;i<num.size();i++)
        res=(res*num[i])%MOD;
    return res;
}
