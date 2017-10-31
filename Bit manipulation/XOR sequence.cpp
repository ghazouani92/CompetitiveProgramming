//https://www.hackerrank.com/challenges/xor-se
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll getp(ll b){
 if(b%2)return -1;
 return 1LL;
}
ll getse(ll b){
   if(b%2)return 2;
 return 0;
}
ll get(ll a){
 ll d = (a / 4) + 1,mod = a % 4;
 ll fr = 1ll * d  * 4LL - 3 + getp(d);
 ll ans[4] = {fr,fr + 1,getse(d),getse(d)};
 return ans[mod]; 
}



int main() {
    int q;
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        cerr << get(r) << " " << get(l - 1);
        cout << (get(r) ^ get(l - 1)) << endl;
    }

    return 0;
}