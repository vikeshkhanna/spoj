#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

//FILE* ifp = fopen(INPUT,"r");
FILE* ifp = stdin;

void build_table(int* t, const int* w, const int wlen)
{
        int pos=1;
        int cnd = 0;
        t[0] = -1;

        while(pos<wlen){
                if(w[pos]==w[cnd])
                        t[pos++]=++cnd;
                else if(cnd>0)
                        cnd = t[cnd];
                else
                        t[pos++]=0;
            }
}


void kmp(int* s,int* w,int slen, int wlen)
{
    int *t = (int*)malloc(sizeof(int)*wlen);
    build_table(t,w,wlen);
    int m=0,i=0;

    while(m+i<wlen)
    {
        if(s[m+i]==w[i])
            if(i==wlen-1)
                printf("%d\n",m);
            else
                i++;
        else
            m = m + i -t[i];
            i = (t[i]==-1?0:t[i]);
    }
}


int main()
{
    int t,n,count;
    fscanf(ifp,"%d",&t);

    FOR(T,t){

    }

    return 0;
}

