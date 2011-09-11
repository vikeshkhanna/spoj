#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define MAX 100
#define CANCEL "cancel"
#define DECLARE "declare"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int t,n,k,a[MAX+1][2],sum;
    char str[10];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
        fscanf(ifp,"%d",&n);
        sum = 0;

        FOR(i,n)
            a[i+1][0] = -1, a[i+1][1] = 0;

        for(int i=1;i<n+1;i++){
            a[i][1] = 1;
            fscanf(ifp,"%s",str);

            if(strcmp(DECLARE,str)){
                    fscanf(ifp,"%d",&k);
                    a[i][0] = k;
                    int j=i, count=0;

                    while(a[j][0]!=-1){
                         if(!(count%2))
                                a[a[j][0]][1] = 0;
                         else
                                a[a[j][0]][1] = 1; //declare
                         j = a[j][0];
                         count++;
                    }
                }
        }

       for(int i=1;i<n+1;i++)
                if(a[i][1]) sum++;
       printf("%d\n",sum);

       for(int i=1;i<n+1;i++)
                if(a[i][1]) printf("%d ",i);
        printf("\n");
    }

    return 0;
}



