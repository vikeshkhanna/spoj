#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <stdio.h>
#define INPUT "input"

#define IMP "This is impossible."
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int t,e,f,n,wcoins;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&e);
            fscanf(ifp,"%d",&f);
            fscanf(ifp,"%d",&n);

            int* p =(int*)malloc(sizeof(int)*n);
            int* w =(int*)malloc(sizeof(int)*n);

            FOR(i,n){
                    fscanf(ifp,"%d",&p[i]);
                    fscanf(ifp,"%d",&w[i]);
            }

            if((wcoins = f-e)<0)
                        printf("%s\n",IMP);
            else
            {
                if(wcoins==0){
                    printf("The minimum amount of money in the piggy-bank is %d.",0);
                    break;
                }

                bool a[wcoins+1][n];
                int worst[wcoins];

                FOR(i,wcoins+1)
                        worst[i]=-1;
                worst[0]=0;

                FOR(j,n)
                        a[0][j]=true;


                for(int i=1;i<=wcoins;i++){
                    FOR(j,n){
                                int wk = i - w[j];

                                if(wk<0 || worst[wk]==-1)
                                    a[i][j]=false;
                                else{
                                        a[i][j]=true;
                                        int amount = worst[wk] + p[j];

                                        if(worst[i]==-1 || amount<worst[i])
                                            worst[i] = amount;
                                }
                        }
                    }

                 if(worst[wcoins]==-1)
                    printf("%s\n",IMP);
                else
                        printf("The minimum amount of money in the piggy-bank is %d.\n",worst[wcoins]);

            /*
             FOR(i,wcoins+1)
                cout<<"i: "<<i<<", worst[i]: "<<worst[i]<<endl;
            */
            }
            delete p;
            delete w;
    }

   return 0;
}

