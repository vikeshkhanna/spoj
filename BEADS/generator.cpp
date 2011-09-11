#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<queue>

#define OUTPUT "test"
#define MAX 1000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

#define MAXT 1000
#define MAX 10001

FILE* ofp = fopen(OUTPUT,"w");
//FILE* ifp = stdin;

void print(int* a,int n)
{
        FOR(i,n)
            printf("%d ",a[i]);

    printf("\n");
}

int main()
{
    srand(time(NULL));
    int t = MAXT/2 + rand()%MAXT/2;
    fprintf(ofp,"%d\n",t);

    FOR(i,MAX)
            fprintf(ofp,"%c",'a');

    fprintf(ofp,"\n");

    FOR(i,t-1)
    {
        int len = 1 + rand()%MAX;

        FOR(i,len)
            fprintf(ofp,"%c",'a' + rand()%26);

        fprintf(ofp,"\n");
    }
    return 0;
}

