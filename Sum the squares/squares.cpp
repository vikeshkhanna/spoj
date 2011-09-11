#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define MAX 648
#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
int squares[] = {0,1,4,9,16,25,36,49,64,81};

int sum_sq(int temp)
{
    int sum=0;

    while(temp>0)
            {
                    sum += squares[temp%10];
                    temp /=10;
            }
    return sum;
}


int main()
{
    int t,m,n,offset=0,ans;
    int dfa[MAX+1][MAX+3];
    int end[8] = {4,16,37,58,89,145,42,20};
    int pos[146];
    pos[4]=1, pos[16]=2, pos[37]=4, pos[58]=5, pos[89]=6,pos[145]=7,pos[42]=8,pos[20]=9;

    for(int i=1;i<=MAX;i++)
    {
        int temp = sum_sq(i),count=0;
        bool br = false;

        while(true){
            if(temp==1)
                br = true;

            FOR(j,8)
                if(temp==end[j])
                    br = true;

            dfa[i][count++] = temp;
            if(br) break;
            temp = sum_sq(temp);
        }

        dfa[i][MAX+1] = temp;
        dfa[i][MAX+2] = count;
    }

    /*
    FOR(i,MAX+3) printf("%d ",dfa[89][i]);
    */
    while(true){

            fscanf(ifp,"%d%d",&m,&n);

            if(m==0 && n==0) break;
            offset = 0;
            printf("%d %d ",m,n);

             if(m>MAX){
                    m = sum_sq(m);
                    offset++;
             }

             if(n>MAX)
             {
                    n = sum_sq(n);
                    offset++;
             }

             if((dfa[m][MAX+1]==1 && dfa[n][MAX+1]!=1) || (dfa[m][MAX+1]!=1 && dfa[n][MAX+1]==1))
                ans=0;
             else
             {
                    int len1 = dfa[m][MAX+2], len2 = dfa[n][MAX+2],count=0,start1=0,start2=0;

                    if(dfa[m][MAX+1]==dfa[n][MAX+1]) //linked list intersection
                    {
                        if(len1>len2)
                                start1 = len1-len2;
                        else
                                start2 = len2-len1;

                        while(dfa[m][start1+count]!=dfa[n][start2+count]) count++;
                        ans = abs(len1-len2) + count*2 + offset + 4 + (((start1>0 && dfa[m][start1-1]==n) ||(start2>0 && dfa[n][start2-1]==m) || m==n)?-2:0);
                    }
                    else
                    {
                            int end1 = dfa[m][MAX+1], end2=dfa[n][MAX+1];
                            int diff = abs(pos[end2]-pos[end1]);

                            ans = len1+len2 + (diff>4?8-diff:diff) + 1;
                    }
              }

            printf("%d\n",ans);

    }

    return 0;
}


