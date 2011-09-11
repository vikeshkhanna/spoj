#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define INPUT "test"
#define MAX 500000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int t,hash[MAX+1],n;
    fscanf(ifp,"%d",&t);

    for(int i=1;i<=MAX;i++)
        hash[i] = (int)sqrt(i);

    FOR(T,t)
    {
        fscanf(ifp,"%d",&n);

        int lim = hash[n],sum=(n==1?0:1),q;

        for(int i=2;i<=lim;i++)
                {
                     if(n%i==0)
                     {
                       q = n/i;

                       if(i!=q)
                            sum += i + q;
                        else
                            sum+=i;
                     }
                }
        printf("%d\n",sum);
    }

   //delete a;
    return 0;
}


