//http://codeforces.com/problemset/problem/566/D
#include <iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define ll long
#define vii vector< ii >
#define f(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define endl '\n'
using namespace std;

class DisjointSets {
private: vi rank,p;
   int cnt=0;
    map < int , int > setSize;
public :
    DisjointSets(int N)
    {
        rank.assign(N,0);
        p.assign(N,0);
        f(i,0,N)setSize[i]=1;
        f(i,0,N)p[i]=i;
        cnt=N;

    }
int numDisjointSets(){return cnt;}
int findset(int i){return (p[i]==i)?i:(p[i]=findset(p[i])); }
bool isSameSet(int i,int j){return findset(i)==findset(j);}
void unifier(int i,int j)
{
    if(!isSameSet(i,j))
    {
          cnt--;
        int x=findset(i),y=findset(j);
        if(rank[x]>rank[y]){p[y]=x;setSize[x]+=setSize[y];}
        else
        {
            p[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;
           setSize[y]+=setSize[x];
        }


    }



}

int getSize(int i){return setSize[findset(i)];}


};


int main()
{
     ios::sync_with_stdio(0);
     int n,q;

     scanf("%d %d",&n,&q);
     int nxt[200006];
     for(int i=0;i<n;i++)nxt[i]=i+1;
     DisjointSets *djs=new DisjointSets(n);
     while(q--)
     {
          int t,y,z;
           scanf("%d %d %d",&t,&y,&z);
          if(t==1)
          {
            y--;z--;
            djs->unifier(y,z);

          }
          else if (t==2)
          {
             y--;z--;
             if(y>z)swap(y,z);
             for(int k=y+1;k<=z;)
             {
                 djs->unifier(k,k-1);
                 int h=nxt[k];
                 nxt[k]=max(h,z);
                 k=h;

             }




          }
          else
            {
                y--;z--;
                (djs->isSameSet(y,z))?puts("YES"):puts("NO");


            }




     }


     return 0;
}