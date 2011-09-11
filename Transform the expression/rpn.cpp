
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
#define MAX 400
#define LBRACE '('
#define RBRACE ')'


#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

void rpn(const char* s,const int low,const int high)
{
    //printf("%d\n",high);
    if(low==high)
        printf("%c",s[low]);
    else{
        if(s[low]==LBRACE && s[high]==RBRACE){
                stack<char> S;
                S.push(s[low]);
                int i=low+1;
                while(i<=high && !S.empty())
                {
                    if(s[i]==LBRACE) S.push(s[i]);
                    else if(s[i]==RBRACE) S.pop();
                    i++;
                }

                if(i==high+1){
                    rpn(s,low+1,high-1);
                    return;
                }
            }

        int countb=0;

        for(int i=low;i<high;i++)
            {
                if(s[i]==LBRACE) countb++;
                else if(s[i]==RBRACE) countb--;
                else if((s[i]<'a' || s[i]>'z') && countb==0)
                {
                    rpn(s,low,i-1);
                    rpn(s,i+1,high);
                    printf("%c",s[i]);
                    return;
                }
            }
       }
}

int main()
{

    int t;
    char s[MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        fscanf(ifp,"%s",s);
        rpn(s,0,strlen(s)-1);
        printf("\n");
    }

    return 0;
}

