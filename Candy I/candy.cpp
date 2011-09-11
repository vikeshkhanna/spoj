#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define MAX 10000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int n,a[MAX];

    while(fscanf(ifp,"%d",&n)>0 && n>0)
    {
            int s=0;
            float avg;

            FOR(i,n)
                fscanf(ifp,"%d",&a[i]), s+=a[i];

            avg = (float)s/n;

            if(avg!=s/n)
                printf("-1\n");
            else
            {
                s=0;
                    FOR(i,n)
                        if(a[i]>avg) s+=a[i]-avg;

                printf("%d\n",s);
            }
    }

    //delete a;
    return 0;
}


