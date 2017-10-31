//http://codeforces.com/problemset/problem/884/D
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> Q;

int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        long long col;
        cin >> col;
        Q.push(-col);
    }
    long long ans = 0;
    if(n % 2 == 0){
        long long f = Q.top();Q.pop();
        long long s = Q.top();Q.pop();
        ans -= f + s;
        Q.push(f + s);
    }
    
    while(Q.size() > 2){
         long long f = Q.top();Q.pop();
         long long s = Q.top();Q.pop();  
         long long t = Q.top();Q.pop();
         ans -= f + s + t;
         Q.push(f + s + t);
    }
    cout << ans;
    return 0;
}