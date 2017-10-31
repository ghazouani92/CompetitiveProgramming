//http://codeforces.com/problemset/problem/818/D
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>

using namespace std;
int cnt[1000056];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,a,lazy = 0;
    cin >> n >> a;

    vi c(n);
    set<int>in;
    for(int i = 0 ; i < n; i++)
        cin >> c[i];
    int i;
    for(i = 0 ; i < n && c[i] != a;i++)
        in.insert(c[i]),cnt[c[i]]++;
    for(int j = i ; j < n ; j++)
            if(c[j] != a)
               {
                 if(in.count(c[j])){
                   if(cnt[c[j]] < lazy)
                     in.erase(c[j]);
                   else cnt[c[j]]++;
                 }
               }
            else lazy++;

    if(in.size() == 0){
        cout << -1;
        return 0;
    }
    int ans = -1;
    for(set<int>::iterator it = in.begin() ; it != in.end() ; it++)
        if(cnt[*it] >= lazy)
    {
        ans = *it;
        break;
    }
    cout << ans;
    return 0;
}