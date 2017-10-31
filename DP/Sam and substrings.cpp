//https://www.hackerrank.com/challenges/sam-and-substrings
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll sumPow[1000056];
ll get(int left,int right){
    if(left == 0)
         return sumPow[right];
    return (sumPow[right] - sumPow[left - 1] + MOD) % MOD;
}

int main() {
    sumPow[0] = 1LL;
    ll cur = 1LL;
    for(int i = 1 ; i < 1000052 ; i++){
        cur *= 10;
        cur %= MOD;
        sumPow[i] = cur + sumPow[i - 1];
        sumPow[i] %= MOD;
    }
    ll ans = 0;
    string s;
    cin >> s;
    for(int i = 0 ; i < (int) s.size() ; i++){
        int cur = s[i] - '0';
        ll toAdd;
        if(i == 0)
            toAdd = get(0,s.size() - 1);
        else if (i == s.size() - 1)
        toAdd = s.size() * get(0,0);
        else {
            toAdd = get(0,s.size() - 1 - i);
            toAdd %= MOD;
            toAdd += i * get(0,0);
            toAdd %= MOD;
            toAdd += i * get(1,s.size()-1-i);
 
        }
        toAdd %= MOD;
        toAdd *= cur;
        toAdd %= MOD;
        ans += toAdd ;
        ans %= MOD;
        
    }
     cout << ans << endl;
 
    return 0;
}
