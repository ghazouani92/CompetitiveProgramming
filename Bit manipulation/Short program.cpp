//http://codeforces.com/problemset/problem/879/C
#include<bits/stdc++.h>
#define same 3
#define reversed 4
using namespace std;
int bits[10];
int getA(){
    int ans = 1023;
    for(int i = 0 ; i < 10 ; i++)
         if(bits[i] == 0)
              ans -= (1 << i);
    return ans;
}
int getO(){
    int ans = 0;
    for(int i = 0; i < 10 ; i++)
        if(bits[i] == 1)
             ans |= (1 << i);
    return ans;
    
}
int getX(){
    int ans = 0;
    for(int i = 0 ; i < 10 ; i++)
         if(bits[i] == reversed)
              ans |= (1 << i);
    return ans;
    
}
int main() {
    for(int i = 0 ; i < 10 ; i++)
        bits[i] = same;
    int n;
    cin >> n;
    vector<char> op(n);
    vector<int> val(n);
    for(int i = 0 ; i < n ; i++)
        cin >> op[i] >> val[i];
    for(int i = 0; i < n ; i++){
        if(op[i] == '&'){
            for(int j = 0 ; j < 10 ; j++)
                 if(! ((1 << j) & val[i]))
                      bits[j] = 0;
        }
        else if(op[i] == '|'){
               for(int j = 0 ; j < 10 ; j++)
                 if(((1 << j) & val[i]))
                      bits[j] = 1;
   
        }
        else{
            for(int j = 0 ; j < 10 ; j++){
                
                if(bits[j] == 0){
                    if((1 << j) & val[i])
                         bits[j] = 1;
                    else bits[j] = 0;
                }
                else if(bits[j] == 1){
                     if((1 << j) & val[i])
                         bits[j] = 0;
                    else bits[j] = 1;
                }
                else{
                    if((1 << j) & val[i]){
                        if(bits[j] == reversed)
                             bits[j] = same;
                        else bits[j] = reversed;
                    }
                   
                }
                     
       }
            
        }
    }
    cout << 3 << endl;
    cout << "& " << getA() << endl;
    cout << "| " << getO() << endl;
    cout << "^ " << getX() << endl;
   
    return 0;
}