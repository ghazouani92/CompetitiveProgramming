//http://codeforces.com/problemset/problem/877/A
//this file has changed
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(),a.end()
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    string arr[5] = {"Danil", "Olya", "Slava", "Ann","Nikita"};
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0 ; i < s.size() ; i++){
        for(int  j = 3 ; j <= 6 && i + j <= s.size() ; j++){
        string ss = s.substr(i,j);
        for(int ii = 0 ; ii < 5 ; ii++)
             cnt+= (ss == arr[ii]);
        }
    }
    cout << ((cnt == 1)?"YES" : "NO") ;
    return 0;
}
