#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define INPUT "input"
#define MAX 10001
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
int bfs(vector<int> adj[],int source,int n,int& farthest)
{
    int color[n+1];
    int d[n+1];
    queue<int> Q;
    Q.push(source);

    FOR(i,n+1)
        color[i] = WHITE;

    color[source]=BLACK;
    d[source]=0;
    int count=0;
    farthest = source;

    while(!Q.empty())
    {
        int node = Q.front(); Q.pop();
        int len = adj[node].size();

        FOR(i,len)
            {
                    int v = adj[node][i];

                    if(color[v]==WHITE){
                        Q.push(v);
                        color[v] = BLACK;
                        count = d[v] = d[node]+1;
                        farthest = v;
                    }
            }
    }
    return count;
}


int main()
{
    int n,u,v,farthest;
    fscanf(ifp,"%d",&n);

    vector<int> adj[MAX];

    FOR(i,n-1){
        fscanf(ifp,"%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*FOR(i,n+1)
        {
            FOR(j,adj[i].size())
                cout<<adj[i][j]<<" ";
            cout<<endl;

        }*/

    bfs(adj,1,n,farthest);
    //cout<<farthest;
    printf("%d\n",bfs(adj,farthest,n,farthest));
    //delete a;
    return 0;
}


