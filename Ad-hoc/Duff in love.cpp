//http://codeforces.com/problemset/problem/588/B
#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){ return (a==0)? b:gcd(b%a,a);}
vector<int>pr;
bool ok[1000005];


int main()
{
    memset(ok,true,sizeof ok);
    for(int i=2;i<=1000000;i++)
    {
        if(ok[i])
        {
            pr.push_back(i);
            for(int  j=i+i;j<=1000000;j+=i)
                ok[j]=false;

        }

    }
long long n;
cin>>n;


for(int i=0;i<pr.size();i++)
    if(n%pr[i]==0)
    {
        while(n%pr[i]==0)n/=pr[i];
        n*=pr[i];
    
    }
    
    
cout<<n;

    return 0;
}