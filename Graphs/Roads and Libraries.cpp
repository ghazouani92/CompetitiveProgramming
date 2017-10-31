//https://www.hackerrank.com/challenges/torque-and-development/problem
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m,c,r,cnt[100005],scc;
vector<int> adj[100005];
bool vis[100005];
void dfs(int u){
    vis[u] = true;
    cnt[scc]++;
    for(int i = 0 ; i < adj[u].size() ; i++)
        if(!vis[adj[u][i]])
             dfs(adj[u][i]);
}

int main() {
    int q;
    cin >> q;
    while(q--){
        cin >> n >> m >> c >> r;
        for(int i = 0 ; i < n ; i++)
            adj[i].clear();
        memset(vis,0,sizeof vis);
        for(int i = 0 ; i < m ; i++){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        memset(cnt,0,sizeof cnt);
        scc = 0;
        for(int i = 0 ; i < n ; i++)
            if(!vis[i]){
                dfs(i);
                scc++;
            }
       long long ans = 0;
       for(int i = 0 ; i < scc ; i++){
           ans += min(1LL * cnt[i] * c,1LL * (cnt[i] - 1) * r + c);
       }
        cout << ans << endl;
    }
    return 0;
}