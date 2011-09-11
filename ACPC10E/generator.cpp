#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define OUTPUT "test"
#define MAX 500000
#define MAXT 200000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ofp = fopen(OUTPUT,"w");
//FILE* ifp = stdin;

int main()
{
   srand(time(NULL));

   int n = MAXT/2 + rand()%MAXT/2;

    FOR(i,n)
        fprintf(ofp,"%d\n",MAX/2 + rand()%MAX/2);
   //delete a;
    return 0;
}


