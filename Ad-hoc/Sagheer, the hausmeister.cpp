//http://codeforces.com/problemset/problem/812/B
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector< ll >
#define vii vector< pair<ll,ll> >
#define vi vector<int>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
using namespace std;
int n,m,cnt[200],a[25][200],ans = 123456789,last;
void solve(int row,int col,int cur){
   if(row < 0){
       cerr << cur << endl;
    ans = min(ans,cur);
    return;
   }
   int vis = 0,step = 0;
   if(col == 0){
    for(int i = 0 ; i < m + 2 && vis < cnt[row] ;i++){
       vis += a[row][i];
       step++;
    }
    if(cnt[row])step--;
    if(row == last)
    {
        solve(- 1,0,cur + step);
        return;
    }
    solve(row - 1,0,cur + 2*step + 1);
    solve(row - 1,m + 1,cur + m + 2);
    return;
   }
    for(int i = m + 1 ; i >= 0 && vis < cnt[row] ;i--){
       vis += a[row][i];
       step++;
    }
    if(cnt[row])
    step--;
    if(row == last)
    {
        solve(- 1,0,cur + step);
        return;
    }
    solve(row - 1,0,cur + m + 2);
    solve(row - 1,m + 1,cur + 2*step + 1);

}
int main()
{
    cin >> n >> m;
    char c;
    for(int i = 0;i < n ; i++)
        for(int j = 0 ; j < m + 2; j++)
            cin >> c, a[i][j] = c - '0' , cnt[i] += a[i][j];
    last= 0;
    while(cnt[last] == 0 && last < n)last++;
    if(last == n){
        cout << 0;
        return 0;
    }
    solve(n - 1,0,0);
    cout << ans ;
    return 0;
}