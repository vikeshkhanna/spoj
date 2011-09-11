#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

void build_table(int* t, const char* w, const int wlen)
{
        int pos=1;
        int cnd = 0;
        t[0] = -1;

        while(pos<wlen){
                if(w[pos]==w[cnd])
                        t[pos++]=cnd++;
                else if(cnd>0)
                        cnd = t[cnd];
                else
                        t[pos++]=0;
            }
}

/*
void kmp(int* s,int* w,int slen, int wlen)
{

    int m=0,i=0;

    while(m+i<wlen)
    {
        if(s[m+i]==w[i])
            if(i==wlen-1)
                printf("%d\n",m);
            else
                i++;
        else
            m = m + i -t[i];
            i = (t[i]==-1?0:t[i]);
    }
}
*/

int main()
{
    int wlen,qlen;
    char c;
    int count=0;

    while(fscanf(ifp,"%d",&wlen)>0)
    {
                if(count++>0)
                    printf("\n");

                qlen = wlen+1;
                char* w = (char*)malloc((sizeof(char))*wlen);
                char* s = (char*)malloc((sizeof(char))*qlen);

                fscanf(ifp,"%s",w);
                getc(ifp); //Waste the \n
                int *t = (int*)malloc(sizeof(int)*wlen);
                build_table(t,w,wlen);
                //FOR(i,wlen)
                  //cout<<t[i]<<" ";

                int head=0,tail=0,i=0,offset=0;
                c = 'a';

        while(c!='\n')
        {
                while(head!=(tail+1)%qlen && (c=getc(ifp))!='\n')
                       {
                            s[tail] =c;
                            tail = (tail+1)%qlen;
                       }
                if((tail+1)%qlen!=head) break;
                //cout<<"head: "<<head<<"tail: "<<tail<<"i: "<<i<<endl;
                while(i<wlen && s[(head+i)%qlen]==w[i])
                        i++;

                if(i==wlen)
                        {
                            i--;
                            printf("%d\n",offset);
                        }

                int difference =  i - t[i];
                head = (head + difference)%qlen;
                offset += difference;
                i = (t[i]==-1?0:t[i]);
        }
        delete w;
        delete s;
        delete t;
    }

    return 0;
}

