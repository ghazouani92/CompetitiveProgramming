//http://codeforces.com/problemset/problem/837/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    string s;
    while(cin >> s){
        
        int loc = 0;
        for(int i = 0 ; i < s.size(); i++)
            loc += (s[i] >= 'A' && s[i] <= 'Z');
        ans = max(ans,loc);
    }      
     cout << ans;
    return 0;
}