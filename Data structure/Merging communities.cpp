//https://www.hackerrank.com/challenges/merging-communities
#include <bits/stdc++.h>
using namespace std;
int root[2000056],sz[2000056]; 
int get(int a){
    if(root[a] == a)
         return a;
    return root[a] = get(root[a]);
}
void merge(int a,int b){
    int ra = get(a),rb = get(b);
    if(ra == rb)return;
    if(sz[ra] > sz[rb])
        swap(ra,rb);
    root[ra] = rb;
    sz[rb] += sz[ra];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        sz[i] = 1,root[i] = i;
    while(q--){
        char c;
        cin >> c;
        if(c == 'M'){
            int a,b;
            cin >> a >> b;
            merge(a,b);
        }
        else {
            int a;
            cin >> a;
            cout << sz[get(a)] << endl;
        }
    }
    return 0; 
}