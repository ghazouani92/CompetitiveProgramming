//http://codeforces.com/problemset/problem/854/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> c(n);
    for(int i = 0 ; i < n ; i++)
    {cin >> c[i].first;c[i].second = i;}
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    set<int> a;
    for(int i = 0 ; i < n ; i++)
        a.insert(k + i);
    long long ans = 0 ;
    vector<int> res(n);
    for(int i = 0 ; i < n ; i++){
        set<int>::iterator it = a.lower_bound(c[i].second);
        res[c[i].second] = *it;
        ans += 1LL * c[i].first * (*it - c[i].second),a.erase(it);
    }
    cout << ans << endl;
    for(int i = 0 ; i < n ; i++)
        cout << res[i] + 1<< " ";
    return 0;
}