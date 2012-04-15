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

//FILE *ifp = fopen("input.txt","r");
FILE *ifp = stdin;


/*
 * @author: Vikesh Khanna
 */

int main()
{
int d,n,m;
fscanf(ifp,"%d",&d);

FOR(T,d)
{
 fscanf(ifp,"%d%d",&n,&m);
 printf("%d\n",((n-m)&((m-1)/2))==0?1:0);
}

system("Pause");
return 0;
}
