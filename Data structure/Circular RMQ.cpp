//http://codeforces.com/contest/52/problem/C
#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false)
using namespace std;
const int INF = 200006;
int n,m;

ll tree[4*INF],lazy[4*INF],a[INF];

void build(int st,int l, int r){
  if(l == r){
    tree[st] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(2 * st,l,mid);
  build(2 * st + 1 , mid + 1,r);
  tree[st] = min(tree[2*st],tree[2*st + 1]);
}
void _update(int st,int l,int r,int ql,int qr,int v){
    if(lazy[st] != 0){

        tree[st] += lazy[st];
        if(l != r){
        lazy[2*st] += lazy[st];
        lazy[2 * st + 1] += lazy[st];
        }
        lazy[st] = 0;
    }
    if(qr < l || ql > r || l > r)
        return;
    if(ql <= l && qr >= r){
        tree[st] += v;
        if(l != r){
            lazy[2*st] += v;
            lazy[2*st + 1] += v;
        }
        return;
    }
    int mid = (l + r) >> 1;
    _update(2*st,l,mid,ql,qr,v);
    _update(2*st + 1,mid + 1,r,ql,qr,v);
    tree[st] = min(tree[2*st],tree[2*st+ 1]);



}
ll get(int st,int l,int r,int ql,int qr){
    if(lazy[st] != 0){

        tree[st] += lazy[st];
        if(l != r){
        lazy[2*st] += lazy[st];
        lazy[2 * st + 1] += lazy[st];
        }
        lazy[st] = 0;
    }
    if(ql == l && qr == r)
        return tree[st];
    int mid = (l + r) >> 1;
    if(ql > mid)
        return get(2 * st + 1,mid + 1,r,ql,qr);
    if(qr <= mid)
        return get(2*st,l,mid,ql,qr);

    ll v1 = get(2*st,l,mid,ql,mid);
    ll v2 = get(2 * st+1,mid + 1,r,mid + 1,qr);
    return min(v1,v2);
}

void update(int l,int r,int v){
_update(1,0,n - 1,l,r,v);
}
ll rmq(int l,int r){
return get(1,0,n - 1,l,r);
}
int main()
{
    fast_io;
    //freopen("test.txt","r",stdin);
    cin >> n;
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    build(1,0,n-1);
    cin >> m;
    while(m--){
        int l,r,v;
        cin >> l >> r;
        if(cin.peek() == ' '){

            cin >> v;
            if(l > r)
                update(l,n-1,v),update(0,r,v);
            else update(l,r,v);
        }
        else {

            if(l > r)
                cout << min(rmq(l,n-1),rmq(0,r)) << endl;
            else cout << rmq(l,r) << endl;

        }
    }
    return 0;
}