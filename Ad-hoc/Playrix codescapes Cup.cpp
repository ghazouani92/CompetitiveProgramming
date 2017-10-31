//http://codeforces.com/problemset/problem/799/A
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,t,k,d;
    cin >> n >> t >> k >> d;
  int ans1 = 0,prp = 0;
    while(prp < n){
        prp += k;
        ans1 += t;
    }
  int ans2 = 0;
  prp = 0;
  for(int i = 1 ; ;i++){
      if(i % t == 0)
          prp += k;
      if(i > d && ((i - d) % t == 0))
          prp += k;
      if(prp >= n){
          ans2 = i;
          break;
      }
  } 
    if(ans1 <= ans2){
        cout << "NO";
    }
    else cout << "YES";
  return 0;
}