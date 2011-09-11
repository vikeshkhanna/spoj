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
#define MAX 1000000//sqrt(2147483647)
#define LIM 1000000000000LL
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    long long x, temp,hash[MAX+1],val1,val2;
    int t,count,low,high;


    for(long long i=0;i<=MAX;i++)
                hash[i] = i*i;

    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        fscanf(ifp,"%lld",&x);
        count=0, low=0;
        high = (long long)sqrt(x);
        //cout<<count<<endl;

        while(low<=high)
        {
                val1 = hash[low];
                val2 = hash[high];

                if(val1+val2>x)
                    high--;
                else if(val1+val2<x)
                    low++;
                else
                   break;

        }

        printf("%s\n",(low<=high?"Yes":"No"));

    }

    return 0;
}

