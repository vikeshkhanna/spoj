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
    int len,t,min,a[MAX],min_index,failed[MAX];
    char str[MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
        fscanf(ifp,"%s",str);
        len = strlen(str);
        char all[len][MAX];

        FOR(i,len)
        {
            int count=0;

            while(count<len){
                all[i][count]=str[(i+count)%len];
                count++;
            }
            all[i][count] = '\0';
        }


        bool failed[len];
        FOR(i,len)
            failed[i]=false;

        FOR(i,len)
        {
               min = 27;

               //cout<<all[i]<<endl;
               FOR(j,len)
                    if(!failed[j] && all[j][i]-'a'<min) min=all[j][i]-'a';

                FOR(j,len)
                    if(!failed[j] && all[j][i]!=min + 'a') failed[j]=true;
        }

        FOR(i,len)
            if(!failed[i]){ printf("%d\n",i+1); break;}
    }

    return 0;
}

