//https://a2oj.com/p?ID=310
#include <bits/stdc++.h>

using namespace std;
int m,b,t;
unsigned short price[500000];
unsigned short taxe[500000];
int first;
int second;
int x;
int sum,ans;

int main()
{



    scanf("%d",&t);
    for(int j=1;j<=t;++j)
    {


       scanf("%d %d",&m,&b);
        ans=0;

        for(int k=0;k<m;k++)scanf("%d",&price[k]);
        for(int k=0;k<m;k++)scanf("%d",&taxe[k]);
        second=m;first=1;

        while(first<=second)
        {

        x=(first+second)/2;

          priority_queue <int> prod;
         sum=0;
          for(int h=0;h<m;h++)prod.push(-(price[h]+(x-1)*taxe[h]));
          for(int w=0;w<x;w++)
          {


              //cout<<r<<endl;
              sum-=prod.top();
              prod.pop();
              if(sum>b)break;

          }

          (sum>b)?second=x-1:first=x+1;

           if(sum<=b) ans=x;

        }


   printf("Case %d: %d\n",j,ans);











    }

    return 0;
}