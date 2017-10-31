//http://codeforces.com/problemset/problem/757/B
#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector< ii >
#define ll long long
#define MOD (int)1e9 + 7

using namespace std;
bool isPrime[100045];
int cnt[100005];
vector<int> pr;
int main(){
ios_base::sync_with_stdio(false);
memset(isPrime,1,sizeof isPrime);
 for(int i = 2 ; i <= 100000 ; i++)
     if(isPrime[i])
     { pr.pb(i);
      for(long long j = i + i ; j <= 100000 ; j += i)
            isPrime[j] = false;
     }
  
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int v;
        cin >> v;
        if(isPrime[v])
             cnt[v]++;
        else{
            for(int j = 0 ; j < pr.size() ;j++){
               
                if(v == 1)break;
                 
                
                if(v % pr[j] == 0){
                    cnt[pr[j]]++;
                    while(v % pr[j] == 0)
                        v /= pr[j];
                }
            }
        }
    }
    int ans = 1;
    for(int i = 2 ; i <= 100000 ; i++)
        ans = max(ans,cnt[i]);
    cout << ans;
}