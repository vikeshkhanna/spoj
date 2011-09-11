#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>

#define INPUT "input"
#define IMP "This is impossible."
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
    int t,n;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
               fscanf(ifp,"%d",&n);
               int a[26][2] = {0}; //0 = in, 1=out

               FOR(i,n)
               {
                      char str[MAX];
                      fscanf(ifp,"%s",&str);

                      int len = strlen(str);
                      a[str[0]-'a'][1]++;
                      a[str[len-1] - 'a'][0]++;
                }

                int start=0;
                int end=0;
                int i=-1;

                /*
                FOR(i,26)
                    {
                            cout<<a[i][0]<<" "<<a[i][1]<<endl;
                    }
                */

                while(++i<26)
                {
                      if(a[i][0]==a[i][1]+1) //in = out + 1
                            end++;
                      else if(a[i][1]== a[i][0] + 1)
                            start++;
                      else if(a[i][0]!=a[i][1])
                            break;
                }

                /*cout<<"i: "<<i<<" start: "<<start<<" end: "<<end<<endl;*/
                if(i==26 && start==1 && end==1)
                    printf("Ordering is possible.\n");
                else
                    printf("The door cannot be opened.\n");
        }
   return 0;
}

