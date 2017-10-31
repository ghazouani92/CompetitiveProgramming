//http://codeforces.com/problemset/problem/813/C
#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define vi vector<int>
#define vii vector< pii >
#define INF (int)1234567889
using namespace std;
vi edges[200056];
int ans,x,mx,dp[200056];
bool visited[200056];
void dfs(int u,int step){
 mx = max(mx,step);
 dp[u] = step;
 visited[u] = true;
 for(int i = 0 ; i < (int)edges[u].size() ; i++){
    int e = edges[u][i];
    if(!visited[e])dfs(e,step + 1);
 }
}
void dfs2(int u,int step){
 visited[u] = true;
 if(step < dp[u]) ans = max(ans,dp[u]);
 for(int i = 0 ; i < (int)edges[u].size() ; i++){
    int e = edges[u][i];
    if(!visited[e])dfs2(e,step + 1);
 }
}
int main(){
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n >> x;
 for(int i = 0 ; i < n - 1 ; i++){
    int u,v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
 }
 dfs(1,0);
 memset(visited,0,sizeof visited);
 ans = dp[x];
 dfs2(x,0);
 cout << 2 * ans;
 return 0;
}