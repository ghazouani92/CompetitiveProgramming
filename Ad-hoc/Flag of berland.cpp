//http://codeforces.com/problemset/problem/837/B
#include <bits/stdc++.h>
using namespace std;
bool check(vector<string> a){
    if(a.size() % 3) return false;
    string s[3] = {"","",""};
    for(int i = 0 ; i < a.size() ; i++)
        s[i / (a.size() / 3)] += a[i];
    for(int i = 0; i < 3 ; i++)
        sort(s[i].begin(),s[i].end());

    for(int i = 0; i < 3; i++)
        if(s[i][0] != s[i][s[i].size() - 1])return false;
    return (s[0][0] != s[1][0] && s[1][0] != s[2][0] && s[0][0] != s[2][0]);      
}
vector<string> rev(vector<string> a){
   vector<string> res(a[0].size());
   for(int i = 0 ; i < a[0].size() ; i++){
       string tmp = "";
       for(int j = 0 ; j < a.size() ; j++)
           tmp += a[j][i];
       res[i] = tmp;    
   }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    if(check(a) || check(rev(a)))cout << "YES";
    else cout << "NO";
    return 0;
}