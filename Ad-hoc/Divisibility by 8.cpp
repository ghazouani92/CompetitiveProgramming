//http://codeforces.com/problemset/problem/550/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
string s;cin>>s;
for(int i=0;i<s.length();i++)
    if(s[i]=='0'){cout<<"YES"<<endl<<'0';return 0;}

for(int i=8;i<1000;i+=8)
{
    stringstream ss;
    ss<<i;
    string x;
    ss>>x;

    int l=x.length();
    int j=0;
    for(int k=0;k<s.length();k++)
    {

       if(s[k]==x[j])j++;

        if(j==l){cout<<"YES"<<endl<<i;return 0;}
    }





}
cout<<"NO"<<endl;

    return 0;
}