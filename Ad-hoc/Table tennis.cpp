//http://codeforces.com/problemset/problem/879/B
#include<bits/stdc++.h>
using namespace std;
int cnt[5006];
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0 ;i < n; i++)
        cin >> a[i];
    int ans = 0,now = 0;
    for(int i = 1; i < 3 * n ; i++){
        int ii = i % n;
        if(cnt[now] >= k){
            ans = a[now];
            break;
        }
        if(a[ii] < a[now])
            cnt[now]++;
        else if(a[ii] > a[now])
              {
                  cnt[now] = 0;
                  now = ii;
                  cnt[now]++;
              }
        
    }
    if(ans)cout << ans;
    else cout << n;
    return 0;
}