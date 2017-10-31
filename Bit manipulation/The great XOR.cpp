//https://www.hackerrank.com/challenges/the-great-xor
#include<bits/stdc++.h>
using namespace std;


int main() {
    int q;
    cin >> q;
    while(q--){
        long long ans = 0,x;
        cin >> x;
        int i = log2(x);
        for(int j = i ; j >= 0 ; j--)
            if(!((1ll << j) & x)){
                ans += (1ll << j);
            }
               
            
       
        cout << ans << endl;
    }
    return 0;
}