//http://codeforces.com/problemset/problem/626/A
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
int u[300],l[300];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1 ;i <= n ; i++)
    {
        char c ;
        cin >> c ;
        if(c == 'U')u[i]++;
        if(c == 'D')u[i]--;
        if(c == 'L')l[i]++;
        if(c == 'R')l[i]--;

    }
    for(int i = 1 ; i <= n ; i++ )
        l[i]+=l[i-1],u[i]+=u[i-1];

    int ans  = 0 ;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i + 1 ; j <= n ; j++)

              if((l[j] - l[i-1] == 0) && (u[j] - u[i-1] == 0))ans++;

    }
    cout << ans ;

    return 0;
}