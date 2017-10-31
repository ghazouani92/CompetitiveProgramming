//http://codeforces.com/problemset/problem/818/B
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
bool done[101];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vi a(n + 1,0),l(m);
    for(int i = 0 ;i < m ; i++)
        cin >> l[i];
    for(int i = 0;i < m - 1 ; i++){
        int val = (l[i] < l[i + 1])? l[i + 1] - l[i] : n + l[i + 1] - l[i];
        if(a[l[i]] && a[l[i]] != val){
            cout << -1;
            return 0;
        }
        a[l[i]] = val;
    }

    for(int i = 0 ; i <= n; i++)
    if(a[i] && done[a[i]]){
        cout << - 1;
        return 0;

    }
    else done[a[i]] = true;
    int j = 1;
    for(int i = 1 ; i <= n ; i++){
        if(a[i])
             cout << a[i] << " ";
        else {
                while(done[j])j++;
                cout << j << " ";
                j++;
        }
    }
    return 0;
}