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
#define MAX 1000000
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2


FILE *ifp = fopen("input.txt","r");
//FILE *ifp = stdin;
FILE *ofp = fopen("output.txt","w");

/*
 * @author: Vikesh Khanna
 */
/* Depth first search visit*/

int main()
{
int t, n, inv;
char* names[10] = {"Aayush","Akash"};
int* a = new int[MAX];
fscanf(ifp,"%d",&t);

a[1] = 0;

FORS(i,2,MAX)
{
          a[i] = a[i/2]^(!(i%2));
          //fprintf(ofp,"%s\n",names[a[i]]);
}

FOR(T,t)
{
     fscanf(ifp,"%d",&n);
     inv = 0;
     
     while(n>=MAX)
     {           
                 inv = inv  ^ (!(n%2));
                 n/=2;            
     }
      
     printf("%s\n",names[a[n]^inv]);
}

system("Pause");
return 0;
}
