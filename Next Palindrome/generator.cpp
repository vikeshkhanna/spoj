#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<queue>

#define OUTPUT "test"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

#define MAXT 10
#define MAX 1000000

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
    fprintf(ofp,"%d\n",t+2);

    FOR(T,t){
        int n = rand()%100;
        FOR(i,n)
            fprintf(ofp,"%d",rand()%10 + 0);
        fprintf(ofp,"\n");
    }

    FOR(i,MAX)
               fprintf(ofp,"9");

    return 0;
}

