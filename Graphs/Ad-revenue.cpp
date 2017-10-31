//https://a2oj.com/p?ID=287
#include <bits/stdc++.h>

using namespace std;
int n;
vector< vector<int> > page,page_reverse,graph;
vector<int>stak;
int a[50005],scc,grp[50005],grp_sum[50005],dp[50005];
bool visited[50005];

void dfs(int u)
{
    visited[u]=true;
    for(int i=0;i<(int)page[u].size();i++)
        if(!visited[page[u][i]])dfs(page[u][i]);
    stak.push_back(u);

}

void _reverse()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<(int)page[i].size();j++)
           page_reverse[page[i][j]].push_back(i);

}
void dfs2(int u)
{
    visited[u]=true;
    grp[u]=scc;
    grp_sum[scc]+=a[u];
    for(int i=0;i<(int)page_reverse[u].size();i++)
        if(!visited[page_reverse[u][i]])dfs2(page_reverse[u][i]);


}
int solve(int u)
{

    if(dp[u]>-1)return dp[u];
    dp[u]=grp_sum[u];
    for(int i=0;i<(int)graph[u].size();i++)
         dp[u]=max(dp[u],grp_sum[u]+solve(graph[u][i]));
     return dp[u];

}



int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {


       memset(visited,false,sizeof visited);
       memset(a,0,sizeof a);
       memset(grp,0,sizeof grp);
       memset(grp_sum,0,sizeof grp_sum);
       memset(dp,-1,sizeof dp);
       page.clear();
       graph.clear();
       page_reverse.clear();
       scanf("%d",&n);
       page.resize(n);
       graph.resize(n);
       page_reverse.resize(n);
       stak.clear();
       for(int i=0;i<n;i++)
       {
           int m;
           scanf("%d %d",&a[i],&m);
           page[i].resize(m);
           for(int j=0;j<m;j++)
            {
            scanf("%d",&page[i][j]);
            }

       }

       scc=0;
       for(int i=0;i<n;i++)
        if(!visited[i])dfs(i);

       _reverse();

       memset(visited,false,sizeof visited);

       for(int i=n-1;i>=0;i--)
        if(!visited[stak[i]]){dfs2(stak[i]);scc++;}

       for(int i=0;i<n;i++)
        for(int j=0;j<(int)page[i].size();j++)
        if(grp[i]!=grp[page[i][j]])
        graph[grp[i]].push_back(grp[page[i][j]]);
        int ans=0;

        for(int i=0;i<scc;i++)
          ans=max(ans,solve(i));

         printf("Case %d: %d\n",tt,ans);


    }
    return 0;
}