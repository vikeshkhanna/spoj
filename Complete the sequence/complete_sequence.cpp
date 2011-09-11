#include<iostream>
#include<fstream>
#include <stdio.h>
#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

//FILE* ifp = fopen(INPUT,"r");
FILE* ifp = stdin;

int main()
{
    int t,s,c;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
        fscanf(ifp,"%d",&s);
        fscanf(ifp,"%d",&c);

        int a[s+c+1][s];

        FOR(i,s){
                FOR(j,s)
                   a[i][j] = -1;
        }
        a[0][0]=s+1;

        for(int i=1;i<=s;i++)
                  fscanf(ifp,"%d",&a[i][0]);

        for(int j=1;j<s;j++){
            int lim = a[0][j-1];

            for(int i=2;i<lim;i++)
                a[i-1][j] = a[i][j-1] - a[i-1][j-1];

            a[0][j] = lim-1;
            }

        /* FOR(i,s+1){
                FOR(j,s)
                    cout<<a[i][j]<<" ";
                cout<<endl;
                }
            cout<<endl;
            }   */

    FOR(i,c){
            int  lim = a[0][s-1];
            a[lim][s-1] = a[lim-1][s-1];
            a[0][s-1]++;

            for(int j=s-2;j>=0;j--)
            {
                lim = a[0][j];
                a[lim][j] = a[lim-1][j] + a[a[0][j+1] - 1][j+1];
                a[0][j]++;
            }
        }

        for(int i=s+1;i<s+c+1;i++)
            printf("%d ",a[i][0]);

        printf("\n");
    }

    return 0;
}
