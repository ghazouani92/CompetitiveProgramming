//http://codeforces.com/problemset/problem/803/D
#include <bits/stdc++.h>
using namespace std;
int k;
vector<string> words;
bool cmp(string a,string b){
    return a.size() < b.size();
}
bool check(int widh){
    int cnt = 0,i = 0;
    while(i < words.size()){
        if(words[i].size() > widh)
             return false;
        int cur = words[i].size();
        i++;
        while(cur <= widh && i < words.size()){
           cur += words[i].size(); 
           i++; 
        }
      //  cerr << cur << endl;
        if(i <= words.size() && cur > widh)
            i--;
        cnt++;
        if(cnt > k)
            return false;
    }
    return true;
}
int main() {
  cin >> k;
     string s;
      cin >> s;
      string tmp = "";
      for(int i = 0 ; i < s.size() ; i++){
          if(s[i] == '-'){
              tmp += "-";
              words.push_back(tmp);
              tmp = "";
          }
          else tmp += s[i];
      }
      words.push_back(tmp + " ");
  while(cin.peek() == ' '){
      string s;
      cin >> s;
      string tmp = "";
      for(int i = 0 ; i < s.size() ; i++){
          if(s[i] == '-'){
              tmp += "-";
              words.push_back(tmp);
              tmp = "";
          }
          else tmp += s[i];
      }
      words.push_back(tmp + " ");
  }
  int n = words.size();
  words[n-1] = words[n-1].substr(0,words[n-1].size() - 1);
  //sort(words.begin(),words.end(),cmp);
  //for(int i = 0 ; i < words.size();i++)
     // cerr << words[i] << "."<< endl;
  int high = 2000000,low = 0,sol;
    
  while(high > low){
     int mid = (low + high)/2;
     // cerr << mid <<  " " <<check(mid)  << endl;
      
     if(check(mid)){
         high = mid;
         sol = mid;
     }
      else low = mid + 1;
  }
  cout << sol;  
  return 0;
}