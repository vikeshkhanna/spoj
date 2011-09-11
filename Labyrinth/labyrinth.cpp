#include<iostream>
#include<fstream>
#include <stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

#define INPUT "input"

#define FREE 0
#define BLOCKED -1
#define GRAY -2
#define BLACK -3
#define WHITE -4
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;


int nr,nc;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

void print(int** a,int r, int c)
{
        FOR(i,r){
            FOR(j,c)
                printf("%d",a[i][j]);
            cout<<endl;
        }
}

void print_pair(pair<int,int> p)
{
    cout<<"("<<p.first<<","<<p.second<<")"<<endl;
}

void dfs_visit(int** a, int r, int c,int scc)
{
    a[r][c] = GRAY;

    if(r>0 && a[r-1][c]==FREE)
            dfs_visit(a,r-1,c,scc);

    if(c>0 && a[r][c-1]==FREE)
            dfs_visit(a,r,c-1,scc);

    if(r<nr-1 && a[r+1][c]==FREE)
            dfs_visit(a,r+1,c,scc);

    if(c<nc-1 && a[r][c+1]==FREE)
            dfs_visit(a,r,c+1,scc);

    a[r][c] =  scc;
}

int dfs(int** a,vector<pair<int,int> >& list)
{

    int scc=1;
    pair<int,int> p;

    FOR(i,nr){
              FOR(j,nc){
                         if(a[i][j]==FREE)
                             {
                                 dfs_visit(a,i,j,scc++);
                                 p.first = i;
                                 p.second = j;
                                 list.push_back(p);
                             }
                }
    }
    return scc-1;
}


int bfs(int** a,int r,int c,pair<int,int>& p)
{
    queue<pair<int,int> > Q;
    p.first=r, p.second=c;
    int color[nr][nc];

    FOR(i,nr)
        FOR(j,nc)
            color[i][j]=WHITE;

    Q.push(p);
    a[r][c]='0';
    color[r][c] = GRAY;
    int d=0;

    while(!Q.empty())
    {
       p = Q.front();   Q.pop();
       r=p.first,c=p.second;

       if(r>0 && a[r-1][c]!=BLOCKED && color[r-1][c]==WHITE)
            {color[r-1][c]=GRAY; p.first=r-1,p.second=c; a[r-1][c] = a[r][c] + 1; Q.push(p);}

        if(c>0 && a[r][c-1]!=BLOCKED  && color[r][c-1]==WHITE)
            {color[r][c-1]=GRAY; p.first=r,p.second=c-1; a[r][c-1] = a[r][c] + 1; Q.push(p); }

        if(r<nr-1 && a[r+1][c]!=BLOCKED && color[r+1][c]==WHITE)
             {color[r+1][c]=GRAY; p.first=r+1,p.second=c; a[r+1][c] = a[r][c] + 1;Q.push(p); }

        if(c<nc-1 && a[r][c+1]!=BLOCKED && color[r][c+1]==WHITE)
              {color[r][c+1]=GRAY; p.first=r,p.second=c+1; a[r][c+1] = a[r][c] + 1; Q.push(p);}

        d = a[r][c]-'0';
        color[r][c] = BLACK;
    }
    return d;
}


int main()
{
    int t;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&nc);
            fscanf(ifp,"%d",&nr);
            int** a= (int**)malloc(sizeof(int*)*nr);

            FOR(i,nr){
                a[i] = (int*)malloc(sizeof(int)*(nc));
                char str[nc+1];
                fscanf(ifp,"%s",str);
                FOR(j,nc)
                    a[i][j]= (str[j]=='#'?-1:0);
            }

            vector<pair<int,int> > list;
            int scc=dfs(a,list);
            int max=0;
            //print(a,nr,nc);
            //int len = list.size();
            FOR(i,scc){
                        pair<int,int> p;
                        bfs(a,list[i].first,list[i].second,p);
                        int temp = bfs(a,p.first,p.second,p);
                        if(temp>max) max=temp;
                        //print(a,nr,nc);
                        //print_pair(p);

            }

            /*FOR(i,list.size())
                cout<<list[i].first<<","<<list[i].second<<endl;;
            */
            printf("Maximum rope length is %d.\n",max);

            FOR(i,nr)
                delete a[i];
            delete a;
    }

    return 0;
}

