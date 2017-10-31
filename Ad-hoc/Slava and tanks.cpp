//http://codeforces.com/problemset/problem/877/C
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(),a.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
	if(n % 2 == 0)
		cout<< n/2 *3<<endl;
     else
		cout<< n/2* 3 + 1<<endl;
	
	for(int i = 2;i <= n;i += 2)
		cout << i << " ";
	for(int i = 1;i <= n;i += 2)
		cout<< i << " ";
	for(int i = 2;i <= n;i += 2)
		cout << i <<" ";
    return 0;
}