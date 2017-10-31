//https://www.hackerrank.com/challenges/even-tree
#include <bits/stdc++.h>
using namespace std;
vector<int> edges[1000006];
int depth[1000056];
bool vis[10000006];
int dfs(int u){
    vis[u] = true;
    depth[u] = 1;
    for(int i = 0 ; i < (int)edges[u].size() ; i++)
        if(!vis[edges[u][i]])
     depth[u] += dfs(edges[u][i]);
    return depth[u];
} 

int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    for(int i = 2 ; i <= n ; i++)
        ans += (depth[i] % 2 == 0);

    cout << ans ;
    return 0;
}