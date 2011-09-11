#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<vector>

#define INPUT "input"
#define IMP "This is impossible."
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1001

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

void dfs_visit(vector<int> a[],const int i,int color[])
{
    color[i]=1; //gray
    int size = a[i].size();

    FOR(j,size){
        int k = a[i][j];

        if(color[k]==0) //still white
            dfs_visit(a,k,color);
       }
    color[i]=2;
}

void dfs(vector<int> a[],int start, int color[])
{
    if(start==-1)
        while(a[++start].size()==0);

    dfs_visit(a,start,color);
}

bool connected(vector<int> a[], int start,int arr[][2])
{
    int color[26];

    FOR(i,26)
        if(arr[i][0]==0 && arr[i][1]==0)
            color[i]=2; //black;
        else
            color[i]=0;

    dfs(a,start,color);

    FOR(i,26)
        if(color[i]!=2)
            return false;
    /*FOR(i,26)
        cout<<color[i]<<endl;
    */
    return true;
}

int main()
{
    int t,n;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
               vector<int> adj[26];
               fscanf(ifp,"%d",&n);
               int a[26][2] = {0}; //0 = in, 1=out
               //cout<<n<<endl;
               /*
                FOR(i,26)
                    {
                            cout<<a[i][0]<<" "<<a[i][1]<<endl;
                    }
                */

               FOR(i,n)
               {
                      char str[MAX];
                      fscanf(ifp,"%s",str);

                      int len = strlen(str);

                      FOR(j,len-1){
                             a[str[j]-'a'][1]++;
                             a[str[j]-'a'][0]++;
                             adj[str[j]-'a'].push_back(str[j+1]-'a');
                      }
                     a[str[len-1] - 'a'][0]++;
                     a[str[0]-'a'][0]--;
                }

                int start=0,istart=-1;
                int end=0;
                int i=-1;


                while(++i<26)
                {
                      if(a[i][0]==a[i][1]+1) //in = out + 1
                            end++;
                      else if(a[i][1]== a[i][0] + 1)
                            {start++;istart=i;}
                      else if(a[i][0]!=a[i][1])
                            break;
                }

                //cout<<"i: "<<i<<" start: "<<start<<" end: "<<end<<connected(adj,a)<<endl;
                if(i==26 && (start==end==1 || start==end==0) && connected(adj,istart,a))
                    printf("Ordering is possible.\n");
                else
                    printf("The door cannot be opened.\n");
        }
   return 0;
}

