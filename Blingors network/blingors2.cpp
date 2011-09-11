#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define parent(i) (int)((i-1)/2)
#define left(i) 2*i+1
#define right(i) 2*i+2

#define INPUT "input"
#define MAX 10
#define MAXN 10000
#define LARGE 4294967295
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef unsigned int uint;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int t,p,v,n,c;
    uint key[MAXN],back[MAXN];
    char str[MAX+1];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&n);
            vector<pair<int,uint> > adj[n];

            FOR(i,n){
                fscanf(ifp,"%s",str);
                fscanf(ifp,"%d",&p);


                FOR(u,p){
                       fscanf(ifp,"%d %d",&v,&c);
                       pair<int,uint> P(v-1,c);
                       adj[i].push_back(P);
                }
            }

             /*FOR(i,n){
                FOR(j,adj[i].size())
                    cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<")";
                cout<<endl;
            }*/

            FOR(i,n)
                    key[i] = LARGE;
            key[0]=0;

            uint sum=0;
            Minheap H(key,back,n);
            /*Prim's algo*/
            while(!H.empty())
            {
                int k = H.extract_min(), len = adj[k].size();
                sum += (uint)key[k];
                //H.print();
                FOR(i,len)
                    H.decrease_key(adj[k][i].first,adj[k][i].second);
                //H.print();
            }

            printf("%u\n",sum);
            /*Minheap H(key,back,n);
            H.print();
            H.extract_min();
            H.print();*/
    }
    //printf("%d\n",(uint)pow(2,32)-1);
    return 0;
}


