#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define INPUT "input"
#define MAX 17
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int t,G,T,A,D;
    long long int hash[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,
                            536870912,1073741824,2147483648,8589934592LL};
    while(true){
            fscanf(ifp,"%d%d%d%d",&G,&T,&A,&D);

            if(G==-1) break;

            int i=0;
            long long x = 0,y, temp;
            x += ((long long)G*T*(T-1))/2;
            temp = G*A + D;

            while(hash[i++]<temp);
            i--;
            y = hash[i] - temp;
            x += hash[i] - 1;
            printf("%d*%d/%d+%d=%lld+%lld\n",G,A,T,D,x,y);
    }

   //delete a;
    return 0;
}


