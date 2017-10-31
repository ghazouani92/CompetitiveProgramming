//http://codeforces.com/problemset/problem/557/A
#include <bits/stdc++.h>

using namespace std;


int main()
{
     int n;
     cin>>n;
     int mx[3],mn[3];
     for(int i=0;i<3;i++)
     cin>>mn[i]>>mx[i];
     int deb=min(mx[0],n-mn[1]-mn[2]);
     for(int d1=deb;d1>=mn[0];d1--)
     {

         for(int d2=mx[1];d2>=mn[1];d2--)
      if(n-d1-d2>=mn[2]&&n-d1-d2<=mx[2])
      {
          cout<<d1<<" "<<d2<<" "<<n-d1-d2<<endl;return 0;
      }

     }

    return 0;
}