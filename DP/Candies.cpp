//https://www.hackerrank.com/challenges/candies/
#include <bits/stdc++.h>
using namespace std;
int r[100005];
long long dp[100005];

int main() {
    int N ; 
    cin >> N ;
    
    for(int i = 0 ; i < N ; i++)
        cin >> r[i] ;
    
   for(int i = 0 ; i < N ; i++)
       dp[i] = 1LL ;
 
     for(int i = 1 ; i < N ; i++)
        if (r[i] > r[i-1]) dp[i] = dp[i-1] + 1 ;
             
        
   
    for(int i = N - 2 ; i >= 0 ; i--)
        if(r[i] > r[ i + 1]) dp[i] = max(dp[i],dp[i+1]+1);
    
  /*  for(int i = 0 ; i < N ;i++)
        cout << dp[i]  << endl; */
    long long res = 0 ;
    for(int i = 0 ; i < N ; i++)
        res += dp[i];
    cout << res ;
    
    return 0;
}
