#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<queue>
#include<algorithm>

#define OUTPUT "test"
#define MAX 1000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

#define MAXT 10
#define MAXW 20
#define MAXN 30000

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
    int t = MAXT/2 + rand()%MAXT/2, a[MAXN];
    char str[MAXN][MAXW+1];
    fprintf(ofp,"%d\n",t);

    FOR(T,t)
    {
        int n = MAXN/2 + rand()%MAXN/2;

        FOR(i,n)
        {
                a[i] = i;
                int w = MAXW/2 + rand()%MAXW/2;

                FOR(j,w)
                    str[i][j] = 'a' + rand()%26;
                str[i][w] = 0;
        }

        fprintf(ofp,"%d\n",n);
        FOR(i,n)
            fprintf(ofp,"%s ",str[i]);

        fprintf(ofp,"\n");

        int total = 100 + rand()%MAXN*MAXW;
        int i=0;
        do{
                i++;
            }while(i<total && next_permutation(a,a+n));

        FOR(i,n)
            fprintf(ofp,"%s ",str[a[i]]);

        fprintf(ofp,"\n");
    }

    return 0;
}

