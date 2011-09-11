#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define parent(i) (int)((i-1)/2)
#define left(i) 2*i+1
#define right(i) 2*i+2

#define INPUT "input"
#define MAX 80
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int n,x;
    char str[MAX+1];

    fscanf(ifp,"%d",&n);

    FOR(N,n)
    {
        fscanf(ifp,"%d%s",&x,str);

        int ptr1 = x-1,ptr2=x;

        while(str[ptr1]!=0){
            str[ptr1++]=str[ptr2++];
        }
        printf("%d %s\n",N+1,str);
    }

    return 0;
}


