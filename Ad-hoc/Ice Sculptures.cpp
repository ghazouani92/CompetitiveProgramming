//http://codeforces.com/problemset/problem/158/D
#include <iostream>
using namespace std;

const int MX=134278;
int a[MX];

int main () {
    int n, cur, ans=-134278666;
    cin >>n;
    for (int t=0; t<n; t++) cin >>a[t];
    for (int d=n/3; d>0; d--)
        if (n%d==0)
            for (int i=0; i<d; i++) {
                cur=0;
                for (int j=i; j<n; j+=d) cur+=a[j];
                if (cur>ans) ans=cur;
            }
    cout <<ans<<endl;
return 0;
}