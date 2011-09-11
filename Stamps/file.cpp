#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define MAXF 1000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
int cmp(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int t,n,f,a[MAXF];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
          fscanf(ifp,"%d%d",&n,&f);

          FOR(i,f)
            fscanf(ifp,"%d",&a[i]);

        qsort(a,f,sizeof(int),cmp);

        int i=f-1,sum=0;

        while(i>=0 && (sum+=a[i])<n) i--;

        printf("Scenario #%d:\n",T+1);

        if(i>=0)
            printf("%d\n",f-i);
        else
            printf("impossible\n");

        printf("\n");
    }

    return 0;
}

