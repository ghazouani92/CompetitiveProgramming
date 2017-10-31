//http://codeforces.com/problemset/problem/548/B
#include <bits/stdc++.h>

using namespace std;
short x[501][501];
int best [501];

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>x[i][j];


    for(int i=0;i<n;i++)
    {
          int ans=0;
        int mx=0;
        for(int j=0;j<m;j++)
        {
           if(x[i][j]==1)mx++;
           else {ans=max(ans,mx);mx=0;}

        }
        ans=max(ans,mx);
        best[i]=ans;

    }






    for(int t=0;t<q;t++)
    {
        short i,j ;
        cin>>i>>j;
        x[i-1][j-1]=1-x[i-1][j-1];
        int mx=0,ans=0;
     for(int k=0;k<m;k++)
     {

         if (x[i-1][k]==1)mx++;
         else {ans=max(ans,mx);mx=0;}

     }
     ans=max(ans,mx);
     best[i-1]=ans;
    for(int f=0;f<n;f++)
        ans=max(ans,best[f]);


       cout<<ans<<endl;

    }



    return 0;
}