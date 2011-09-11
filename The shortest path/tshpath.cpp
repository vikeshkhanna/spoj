#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>


#define INPUT "test"
#define MAXLEN 10
#define MAXN 10000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE *ifp = fopen("input.txt","r");
//FILE *ifp = stdin;


/*
 * @author: Vikesh Khanna
 */
struct edge
{
     int v,w;
};

class ii
{
     public:
             int v,d;        
             
             ii(int x, int y)
             {
                    v=x,d=y;       
             }
};

class compare
{
  public:
         bool operator()(ii& x, ii& y)
          {
               return x.d > y.d;     
          }    
};

//djikstra
int djikstra(int start, int end, vector<edge> adj[MAXN], int n)
{
      int d[n];
      //int val = (int)pow(2.0,31.0)-1;
      int val = 200001;
      
      //cout<<val<<endl;
      
      FOR(i,n)
              d[i] = val;
      
      priority_queue<ii,vector<ii>, compare > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      
      d[start] = 0;
      Q.push(ii(start,0));
      
      // iterate while queue is not empty
      while(!Q.empty()) {
           // fetch the nearest element
            //system("Pause");
            ii top = Q.top();
            Q.pop();
                        
            // v is vertex index, d is the distance
            int v = top.v, ds = top.d;

            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            if(ds <= d[v]) {
                  // iterate through all outcoming edges from v
                  int len = adj[v].size();
                  FOR(i,len)
                   {
                        int v2 = adj[v][i].v, cost = adj[v][i].w;
                        if(d[v2] > d[v] + cost) {
                              // update distance if possible
                              d[v2] = d[v] + cost;
                              // add the vertex to queue
                              Q.push(ii(v2,d[v2]));
                        }
                  }
            }
      }
      
      return d[end]; 
}


//mapping
int get_index(char map[][MAXLEN+1], char str[MAXLEN+1], int n)
{
    FOR(i,n)
    {
            if(!strcmp(map[i],str))
                                   return i;        
    }
    
    return -1;
}


int main()
{
int s,n,p;
vector<edge> adj[MAXN];
char map[MAXN][MAXLEN+1];

fscanf(ifp,"%d",&s);

FOR(T,s)
{
     fscanf(ifp,"%d",&n);           
     FOR(i,n) //i is the current city index
     {
             fscanf(ifp,"%s",map[i]);
             fscanf(ifp,"%d",&p);
             
             FOR(j,p)
             {
                     int v,w;
                     fscanf(ifp,"%d%d",&v,&w);
                     
                     struct edge e;
                     e.v = v-1;
                     e.w = w; 
                     adj[i].push_back(e);  
             }
     }   
     /*FOR(i,n)
     {
             cout<<map[i]<<endl;
             
             FOR(j,adj[i].size())
             {
                     cout<<adj[i][j].v<<" ";        
             }        
             cout<<endl;
     }
     */

    int q;
    char temp[MAXLEN+1];
    fscanf(ifp,"%d",&q);
        
    FOR(i,q)
    {
            fscanf(ifp,"%s",temp);
            int start = get_index(map,temp,n); 
 
            fscanf(ifp,"%s",temp);
            int end = get_index(map,temp,n); 
            
            printf("%d\n",djikstra(start,end,adj,n));
    }
}



system("Pause");
return 0;
}
