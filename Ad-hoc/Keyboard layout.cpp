//http://codeforces.com/problemset/problem/831/B
#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector< ii >
#define ll long long
#define MOD (int)1e9 + 7
using namespace std;
map<char ,int> pos;
bool digit(char c){
    return c >= '0' && c <= '9';
}
bool upper(char c){
    return c >= 'A' && c <= 'Z';
}
char toUpper(char c){
 return c + 'A' - 'a';
}
char toLower(char c){
 return c + 'a' - 'A';
}
int main(){
ios_base::sync_with_stdio(false);
     string a,b,d;
     cin >> a >> b >> d;
     for(int i = 0 ; i < a.size() ; i++)
            pos[a[i]] = i;
    for(int i = 0 ; i < d.size() ; i++){
        if(digit(d[i]))
            continue;
        if(upper(d[i])){
            d[i] = toUpper(b[pos[toLower(d[i])]]);
        }
        else d[i] = b[pos[d[i]]];
    }
    cout << d;
    return 0;
}