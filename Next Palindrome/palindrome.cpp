#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "test"
#define MAX 1000000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

/*
bool solve(char str[],const int low,const int high)
{
    if(low>=high)
        return false;
    else
        {
            cout<<"low: "<<low<<"high" <<high<<endl;

            bool ret = solve(str,low+1,high-1);

            if(str[low]!=str[high]){
                if(str[high]<str[low])
                    str[high] = str[low];
                else
                {
                     if(ret)
                        str[high] = str[low];
                     else{
                            str[low] = str[high] = str[low]+1;
                            int l=low+1, h= high-1;

                            while(l<=h)
                            { str[l] = str[h] = '0'; l++; h--; }
                        }
                }
                ret = true;
            }
            return ret;
        }
}
*/
bool solve(char str[],int low, int high)
{
    int len  = high - low + 1,l,h,lz=0,hz=-1;
    bool ret = false;

    if(len%2) {
            l = len/2-1, h = len/2 + 1;

            while(l>=0)
            {
                if(str[l]<str[h]){ str[len/2]++; ret = true; break; }
                else if(str[l]>str[h]) break;
                l--, h++;
            }
    }
    else l = len/2-1, h = len/2;

    while(l>=0)
    {
        if(str[l]>str[h])
            {
                str[h] = str[l];
                ret = true;
            }
        else if(str[l]<str[h])
            {
                if(ret)
                    str[h] = str[l];
                else
                    {
                        str[l] = str[h] = str[l] +1;
                        lz = l+1, hz = h-1;
                        ret = true;
                    }
            }

        l--;h++;
    }

    while(lz<=hz)
    {
        str[lz] = str[hz] = '0';
        lz++; hz--;
    }
}

void add1(char str[])
{
    int i,len = strlen(str);

    for(i=len-1;i>=0;i--){
                if(str[i]=='9') str[i]='0';
                else { str[i]++; break; }
        }

    if(i<0){
            str[0] = '1';
            str[len] = '0';
            str[len+1] = 0;
        }
}

int main()
{
    int t;
    char str[MAX+2];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
        fscanf(ifp,"%s",str);
        int len = strlen(str);

       add1(str);
       solve(str,0,strlen(str)-1);
       printf("%s\n",str);
    }
    //delete a;
    return 0;
}


