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

#define MAXLEN 10
#define MAX 10000000
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

//FILE *ifp = fopen("input.txt","r");
FILE *ifp = stdin;
//FILE *ofp = stdout;

/*
 * @author: Vikesh Khanna
 */
int f(int x)
{
    int cnt=1;
    
    while(x!)
    {
               if(x&1) cnt +=2, x = (3*x+1)>>1;
               else cnt+=1, x >>=1;                        
    }
    return cnt;    
}

int main()
{
int i,j;

while(fscanf(ifp,"%d%d",&i,&j)!=EOF)
{
    int max_cycle = 0;                              
    int l = min(i,j), h=max(i,j);
    
    FORS(s,l,h+1)
    {
               max_cycle = max(max_cycle,f(s));
    }  
    
    printf("%d %d %d\n",i,j,max_cycle);                                                                  
}

//dfs(a);


system("Pause");
return 0;
}
