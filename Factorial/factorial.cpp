#include<iostream>
#include<fstream>
#include <stdio.h>
#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

//FILE* ifp = fopen(INPUT,"r");
FILE* ifp = stdin;

int main()
{
    int t,n,count;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&n);

            count=0;

            while(n!=0){
                count+=n/5;
                n = n/5;
             }
            printf("%d\n",count);
    }

    return 0;
}
