//http://codeforces.com/problemset/problem/566/F
#include <iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define ll long
#define vii vector< ii >
#define f(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define endl '\n'
using namespace std;
int dp[2000002];
int x[1000002];
int y[1000002];



int main()
{
   // freopen("in.in","r",stdin);
     ios::sync_with_stdio(0);

     int n;
     scanf("%d",&n);



    memset(dp,0,2000002*sizeof(int));
    memset(x,0,1000002*sizeof(int));


     for(int i=0;i<n;i++)
     {

         scanf("%d",y+i);x[y[i]]++;
     }
     int mx=y[n-1];
     for(int i=0;i<n;i++)
     {

         for(int k=2*y[i];k<=2*mx;k+=y[i])
         {
           dp[k]=max(dp[k],1+dp[y[i]]);

         }

     }
     int ans=0;
     for(int i=0;i<n;i++)
        ans=max(ans,dp[y[i]]);
        cout<<ans+1;
     return 0;
}