//https://www.hackerrank.com/challenges/coin-change
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pi (double)3.14159265359;
#define endl '\n'
#define INF 1000000
#define MOD (long)1e8+7

using namespace std;
int n,m;
int coins[55];

long long dp[55][255];
bool done[55][255];
long long solve(int c,int s)
{
    if(c>=m||s<0)return 0;
    if(s==0)return 1;


    if(done[c][s])return dp[c][s];
    done[c][s]=true;

    dp[c][s]=solve(c+1,s)+solve(c,s-coins[c]);

    return dp[c][s];

}


int main()
{

    cin>>n>>m;
    for(int i=0;i<m;i++)
       cin>>coins[i];

      solve(0,n);
      cout<<dp[0][n];



    return 0;
}
