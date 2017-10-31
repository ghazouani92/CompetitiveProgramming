//http://codeforces.com/problemset/problem/835/B
#include <bits/stdc++.h>

using namespace std;
int diff[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int k;
    string n;
    cin >> k >> n;
    sort(n.begin(),n.end());
    int cnt = 0;
    for(int i = 0 ; i < n.size() ; i++)
        cnt += n[i] - '0' , diff[i] = '9' - n[i];
    if(cnt >= k){
        cout  << 0;
        return 0;
    }
    k -= cnt;
    for(int i = 0 ; i < n.size() ; i++){
        if(i)
            diff[i] += diff[i - 1];
        if(diff[i] >= k){
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}