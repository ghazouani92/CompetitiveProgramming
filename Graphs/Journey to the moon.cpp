//https://www.hackerrank.com/challenges/journey-to-the-moon
#include <bits/stdc++.h>
using namespace std;
vector<int> same[1000056];
bool vis[1000056];
int sz[1000056],scc;
void dfs(int u){
    vis[u] = true;
    sz[scc]++;
    for(int i = 0 ; i < (int)same[u].size() ; i++)
        if(!vis[same[u][i]])
            dfs(same[u][i]);
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    while(p--){
        int u,v;
        cin >> u >> v;
        same[u].push_back(v);
        same[v].push_back(u);
    }
    for(int i = 0 ; i < n ; i++)
        if(!vis[i])dfs(i),scc++;
    long long ans = 0,tot = 0;
    for(int i = 0; i < scc ; i++){
        ans += sz[i] * (n - sz[i]);
    }
    cout << ans / 2;
    return 0;
}