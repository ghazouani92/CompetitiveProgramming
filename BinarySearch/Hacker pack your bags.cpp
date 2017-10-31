//http://codeforces.com/problemset/problem/822/C
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define inf  (ll)1e9
#define F first
#define S second
using namespace std;
vector< pii > v[1000056];
vector< pair<int, pii > > entry;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        int l,r,c;
        cin >> l >> r >> c;
        entry.pb(mp(l,mp(r,c)));
        v[r - l + 1].pb(mp(l,c));
    }
    for(int i = 0 ; i < 1000000 ; i++)
        sort(all(v[i]));
    for(int i = 0; i < 1000000 ; i++){
        for(int j = (int)v[i].size() - 2 ; j >= 0 ; j--){
            v[i][j].S = min(v[i][j].S,v[i][j + 1].S);
        }
    }
    long long ans = 3 * inf;
    for(int i = 0 ; i < (int)entry.size() ; i++){
        long long curCost = entry[i].S.S;
        int st = entry[i].F, en = entry[i].S.F;
        int len = en - st + 1;
        if(len >= x || v[x - len].size() == 0)
             continue;
        int rem = x - len;
        int from = en + 1;
        vector< pii > :: iterator it = lower_bound(all(v[rem]),mp(from,0));
        if(it == v[rem].end())
            continue;
        curCost += (*it).S;
        ans = min(ans,curCost);
    }
    cout << ((ans == 3 * inf)? -1 : ans);
    
    return 0;
}