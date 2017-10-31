//https://www.hackerrank.com/contests/w33/challenges/transform-to-palindrome
#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;
vi edge[1000056];
bool vis[1000023];
int root[1000056],sc,n,k,m,dp[1001][1001];
void dfs(int u){
    root[u] = sc;
    vis[u] = true;
    for(int i = 0 ; i < (int)edge[u].size() ; i++)
        if(!vis[edge[u][i]])
                dfs(edge[u][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    while(k--){
        int u,v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i++)
        if(!vis[i])
              dfs(i),sc++;
    vi s(m);
    for(int i = 0 ; i < m ; i++)cin >> s[i];
    for(int i = 0 ; i < m ; i++)
        dp[i][i] = 1;
     for (int j = 2; j <= m; j++)
    {
        for (int i = 0; i < m - j + 1; i++)
        {
            int k = i + j - 1;
            if (root[s[i]] == root[s[k]] && j == 2)
               dp[i][k] = 2;
            else if (root[s[i]] == root[s[k]])
               dp[i][k] = dp[i+1][k-1] + 2;
            else
               dp[i][k] = max(dp[i][k-1], dp[i+1][k]);
        }
    }
    cout << dp[0][m-1];
    return 0;
}