#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int gcd(int a, int b)
{
        int r1 = (a>b?a:b);
        int r0 = (r1==a?b:a);
        int r=1;

        while(r!=0)
        {
                r = r1%r0;
                r1 = r0;
                r0 = r;
        }

        return r1;
}

int main()
{
    int n;
    fscanf(ifp,"%d",&n);
    int* a = (int*)malloc(sizeof(int)*n);
    int* d = (int*)malloc(sizeof(int)*(n-1));


    FOR(i,n)
       fscanf(ifp,"%d",&a[i]);

    qsort(a,n,sizeof(int),cmp);

    FOR(i,n-1)
        d[i] = a[i+1] - a[i];

    int g=d[0],s=0;
    FOR(i,n-1)
        g=gcd(g,d[i]);

    FOR(i,n-1)
        s+=d[i]/g-1;

    printf("%d\n",s);
    delete a;
    delete d;
    return 0;
}

