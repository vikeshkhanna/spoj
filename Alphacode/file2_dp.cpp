#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define MAX 5000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    char str[MAX+1];
    long long val[MAX+1];

    while(fscanf(ifp,"%s",str)>0 && strcmp(str,"0"))
    {
        int len = strlen(str);
        val[len] = 1;

        if(str[len-1]=='0') val[len-1] = 0;
        else val[len-1] = 1;

        for(int i=len-2;i>=0;i--){

                if(str[i]=='0')
                    val[i]=0;
                else
                {
                    val[i] = val[i+1];

                   short x = (str[i] - '0')*10 + str[i+1] - '0';
                   if(x<=26)
                        val[i] += val[i+2];
                    }
                }
            printf("%lld\n",val[0]);
        }

    //delete a;
    return 0;
}


