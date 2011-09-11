#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>

#define INPUT "test"

#define MAX 10001
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;


int nr,nc;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

void print(int* a,int n)
{
        FOR(i,n)
            printf("%d ",a[i]);

    printf("\n");
}

int main()
{
    int len,t;
    char str[MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t){

        //printf("%d\n");
        //sleep(100);
    }

    return 0;
}

