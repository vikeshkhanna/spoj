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

long long fun(char str[MAX+1],int low,int high)
{
    if(str[low]=='0')
     return 0;
    else if(low>=high){
        return 1;
    }

    else
    {
        int count=0;
        count += fun(str,low+1,high);

        if(low<=high-1)
        {
            short x;
            x = (str[low]-'0')*10 + (str[low+1]-'0');

            if(x<=26)
                count+= fun(str,low+2,high);
        }
        return count;
    }
}

int main()
{
    char str[MAX+1];

    while(fscanf(ifp,"%s",str)>0 && strcmp(str,"0"))
            printf("%lld\n",fun(str,0,strlen(str)-1));

    //delete a;
    return 0;
}


