//https://www.hackerrank.com/challenges/kruskalmstrsub/
#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
int root[4000];
priority_queue<pair<int,pair<int,int> > > edges;

int get(int i){
    return (root[i] == i)? i : root[i] = get(root[i]);//path compression
}
bool merge(int x,int y){
    int rx = get(x),ry = get(y);
    if(rx == ry)
         return false;
    root[rx] = ry;
    return true;
}


int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        root[i] = i;
    int ans = 0;
    for(int i = 0 ; i < m ; i++)
    {
        int x,y,r;
        cin >> x >> y >> r;
        edges.push(mp(-r,mp(x,y)));
    }
    while(!edges.empty()){
        pair<int,pair<int,int> > front = edges.top();edges.pop();
        if(merge(front.S.F,front.S.S))
            ans -= front.F;
    }
    cout << ans;
    return 0;
}