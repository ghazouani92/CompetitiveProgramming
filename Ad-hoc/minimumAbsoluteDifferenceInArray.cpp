#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,ans = 5000000000;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 1 ; i < n ; i++)
        ans = min(ans,a[i] - a[i - 1]);
    cout << ans;
    return 0;
}
