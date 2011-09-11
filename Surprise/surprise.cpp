#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define WALL '#'
#define FREE '-'
#define MAN '*'

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1025
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
int m,n;

int main()
{
    int t,count;
    char c='a',str[MAX];
    fscanf(ifp,"%d",&t);
    fgetc(ifp);
    //cout<<(int)'\r'<<endl;

    FOR(T,t)
    {
            count=0;
            while((c=fgetc(ifp))>0 && c!='\n')
                    str[count++]=c;
            str[count]=0;

            int len = strlen(str), lim = len/2;

            FOR(i,lim){
                char temp = str[i];
                str[i] = str[len - i -1];
                str[len-i-1] = temp;
            }
            printf("%s\n",str);
    }


    return 0;
}



