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
        min = 26;

        FOR(i,len){
            failed[i]=false;
            if((a[i] = str[i] - 'a')<min){
                    min=a[i];
                    min_index = i;
                }
            }

        //cout<<min_index<<endl;
        //print(a,len);
        int start1=min_index, ptr1=min_index+1, start2, ptr2;
        bool contest=false;

        while(ptr1!=start1)
        {
            //cout<<"ptr1: "<<ptr1<<",start1: "<<start1<<",ptr2: "<<ptr2<<",start2: "<<start2; if(contest) cout<<",comparing: "<<str[ptr1]<<str[ptr2]; cout<<endl;
            if(contest){
                    if(a[ptr2]<a[ptr1]){
                            failed[start1]=true;
                            start1=start2;
                            ptr1=(start2+1)%len;
                            contest=false;
                        }
                    else if(a[ptr1]<a[ptr2]){
                        failed[start2]=true;
                        ptr1 = start2+1;
                        contest = false;
                        }
                    else{
                            //cout<<" compare ahead\n";
                            ptr1 = (ptr1+1)%len;
                            ptr2 = (ptr2+1)%len;
                        }
                }
            else{
                    if(a[ptr1]==min &&!failed[ptr1]){
                            start2 = ptr1;
                            ptr1 = (start1 + 1)%len;
                            ptr2 = (start2 + 1)%len;
                            contest = true;
                    }
                    else
                            ptr1 = (ptr1+1)%len;

            }
        }
        printf("%d\n",start1+1);
        //sleep(100);
    }

    return 0;
}

