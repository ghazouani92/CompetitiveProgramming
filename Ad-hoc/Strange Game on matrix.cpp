//http://codeforces.com/problemset/problem/873/C
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define clr(a) memset(a,0,sizeof a)

using namespace std;
int a[200][200];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
        cin >> a[i][j];
    int tot = 0,mn = 0;
    for(int  i = 0 ; i < m ; i++){
        int best = 0,bk = 0,numOnes = 0;
        for(int j = 0 ; j < n ;j++)
        {
            if(a[j][i] == 1){
               numOnes++;
               int cnt = 0;
               for(int jj = j ; jj < min(j + k,n) ; jj++)
                 cnt += a[jj][i];
              
               if(cnt > best){
                   
                  best = cnt;
                  bk = numOnes - 1;
               }
            }

        }
  
        tot += best;
        mn += bk;

    }
    cout << tot << " " << mn;
    return 0;
}