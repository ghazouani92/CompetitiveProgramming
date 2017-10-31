//http://codeforces.com/problemset/problem/626/B
#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define ll long long
#define all(v) v.begin(),v.end()
#define mp make_pair
#define F first
#define S second
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n ;
    cin >> n;
    int r=0,b=0,g=0;
    char R='R',B='B',G='G';
    for(int i = 0 ; i <  n ; i++)
    {
        char c ;cin >> c;
        if(c=='B') b++;
        if(c=='R') r++;
        if(c=='G') g++;
    }
    if(b&&r&&g) {cout<<"BGR"; return 0;}
    if(g > b){swap(b,g);swap(B,G);}
    if(g > r){swap(r,g);swap(R,G);}
    if(r > b){swap(b,r);swap(B,R);}
    if(r >= 2) {cout<<"BGR" ; return 0;}
    if(b >=1 && !r ) {cout << B ;  return 0;}
    if(b ==1 && r==1){cout << G ;return 0;}
    if(G < R) cout << G << R;
    else cout << R << G;
    return 0;
}