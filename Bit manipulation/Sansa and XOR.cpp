//https://www.hackerrank.com/challenges/sansa-and-xor
#include <bits/stdc++.h>
using namespace std;
int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if((1ll*(i + 1) * (n - i)) & 1LL)
                ans ^= a[i];
        }
        cout << ans << endl;
    }
    return 0;
}