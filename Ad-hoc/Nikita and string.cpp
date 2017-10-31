//http://codeforces.com/problemset/problem/877/B
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(),a.end()
using namespace std;
const int MOD = 1e9 + 7;
int pref[2][100000];
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    // aaaaaaaaaaa.... or bbbb.........
    int ans = 0,cnt = 0;
    for(int i = 0; i < s.size() ; i++){
        if(s[i] == 'a')
             ans++;
        else cnt++;
    }
    ans = max(ans,cnt);
    for(int i = 0 ; i < s.size() ; i++){

        pref[0][i + 1] += pref[0][i],pref[1][i + 1] += pref[1][i];
        pref[s[i] - 'a'][i + 1]++;
    }
    for(int i = 0 ; i <= s.size() ; i++)
    for(int j = i + 1 ; j <= s.size() ; j++){
        int now = pref[0][i] + pref[1][j] - pref[1][i] + pref[0][s.size()] - pref[0][j];
        ans = max(ans,now);
    }
    cout << ans;
    return 0;
}