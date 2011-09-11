#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>

#define MAXLEN 10
#define MAX 1000
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;
typedef unsigned int uint;

//FILE *ifp = fopen("input.txt","r");
//FILE *ifp = stdin;
//FILE *ofp = stdout;
//FILE *ofp = fopen("output.txt","w+");

/*
 * @author: Vikesh Khanna
 */
ifstream in("input.txt",ifstream::in);

int main()
{
int t, hash[26];
char enc[MAX+1], dec[MAX+1];

in>>t;
in.getline(enc,MAX+1,'\n');
        
FOR(T,t)
{
        in.getline(enc,MAX+1,'\n');
        memset(hash,0,sizeof(int)*26);
        //cout<<enc<<endl;
        
        int len = strlen(enc), maxval=0, maxi=0;
        bool multiple=false;
        
        FOR(i,len)
        {
                  //cout<<enc[i]<<" ";
                  if(enc[i]!=' '){
                               int val = ++hash[enc[i] - 'A'];
                               
                               if(val==maxval)
                               {
                                          multiple = true;               
                               }
                               else if(val>maxval)
                               {
                                             maxval =  val;
                                             maxi = enc[i]-'A';
                                             multiple = false;             
                               }
                  }        
        }
        
        //FOR(i,26) cout<<hash[i]<< " ";
        //cout<<endl;
        //cout<<maxi<<endl;
        
        if(multiple)
                    printf("NOT POSSIBLE\n");
        else
        {
                int d = (maxi > 4 ? maxi-4 : 4 - maxi);
                printf("%d ",d);
                
                FOR(i,len)
                {
                          printf("%c",enc[i]==' ' ? enc[i] : ('A' + (26 + enc[i]- 'A' - d)%26));          
                }
                printf("\n");
        }        
}

system("Pause");
return 0;
}
