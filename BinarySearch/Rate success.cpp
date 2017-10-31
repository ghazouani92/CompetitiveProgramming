//http://codeforces.com/problemset/problem/807/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
      int x,y,p,q;
      cin >> x >> y >> p >> q;
      long long high = 10000000000,low = 0;
      long long a = 1ll * x * q;
      long long b = 1ll * y * p;
      if(a == b){
        cout << 0 << endl;
        continue;
      }
      long long ans = -1;
      while(low < high){
        long long mid = (low + high)/2;
        long long xx = 1ll*p * mid,yy =1ll* q * mid;
        if(yy >= y && xx >= x && yy - y >= xx - x)
        {
            ans = yy - y;
            high = mid;
        }
        else low = mid + 1;
      }
      cout << ans << endl;
    }
    return 0;
}