//http://codeforces.com/problemset/problem/884/C
#include<bits/stdc++.h>

using namespace std;
int root[1000056],sz[1000056],p[1000056];
bool done[1000056];
int get(int a){
 if(root[a] == a)
     return a;
 return root[a] = get(root[a]);
}
void _merge(int a,int b){
  int ra = get(a),rb = get(b);
  if(ra != rb){
     root[ra] = rb;
     sz[rb] += sz[ra];
  }
 }

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++)
        {cin >> p[i];p[i]--;}
    for(int i = 0;i < n ; i++)
        root[i] = i,sz[i] = 1;
    for(int i = 0;i < n ; i++)
         _merge(i,p[i]);
    long long ans = 0;
    vector<int> groups;
    for(int i = 0; i < n ; i++){
        int r = get(i);
        if(done[r])
             continue;
        done[r] = true;
        groups.push_back(sz[r]);
    }
 
    if(groups.size() < 2)
        ans = 1ll * n * n;
    else {
        sort(groups.begin(),groups.end());
        reverse(groups.begin(),groups.end());
        ans = 1LL * (groups[0] + groups[1]) * (groups[0] + groups[1]);
        for(int i = 2; i < groups.size() ; i++)
            ans += 1ll * groups[i] * (groups[i]);
    }
    cout << ans;
    return 0;
}