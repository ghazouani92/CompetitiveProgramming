//http://codeforces.com/problemset/problem/812/C
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

using namespace std;
int _k;
bool cmp( pair<ll,ll> a, pair<ll,ll> b){
    return a.F + _k * a.S < b.F + _k * b.S;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,s;
    cin >> n >> s;
    vii a;
    for(int i = 0 ; i < n ; i++){
        int p;
        cin >> p;
        a.pb(mp(p,i+1));
    }
    sort(all(a));
    int high  = n , low = 0;
    ll ans = 0, cost = 0;
    while(high >= low){
        int k = (high + low) / 2;
        _k = k;
        sort(all(a),cmp);
        ll cur = 0;
        for(int i = 0 ; i < k ; i++)
           cur += 1LL * a[i].F + (a[i].S * k * 1LL);
        if(cur <= s){
            ans = k;
            cost = cur;
            low = k + 1 ;
        }
        else high = k - 1;

    }
    cout << ans << " " << cost;
    return 0;
}