#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "test"
#define MAX 81
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

int lcs;
char str1[MAX];
char str2[MAX];


void print(int** a,int nr, int nc)
{
        FOR(i,nr){
            FOR(j,nc)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    printf("\n");
}

class Node
{
        public:
            Node* ptr[26];

        Node()
        {
                FOR(i,26)
                    ptr[i]=NULL;
        }
};


void solve(const int* const* b,int r,int c,char* str, Node* root,int len=0)
{
    cout<<"r: "<<r<<",c: "<<c<<endl;

    if(len==lcs){
            //printf("%s\n",str);
            int len = strlen(str);
            Node* node = root;

            for(int i=len-1;i>=0;i--)
            {
                int index = str[i] - 'a';
                //cout<<index<<" ";
                if((node->ptr)[index]==NULL){ //cout<<"Null found"<<endl;
                            (node->ptr)[index] = new Node();}
                node = (node->ptr)[index];
            }
    }

    else if(r>0 && c>0){
           int adj = b[r][c];
           short pos=0;

           while(adj>0)
           {
                short bit = adj&1;

                if(bit==1)
                {
                    if(pos==0) //up
                        solve(b,r-1,c,str,root,len);
                    else if(pos==2) //left
                        solve(b,r,c-1,str,root,len);
                    else
                        {
                            str[len] = str1[r-1];
                            solve(b,r-1,c-1,str,root,len+1);
                        }
                }
                //printf("%d ",bit);
                adj = adj>>1;
                pos++;
            }
    }
}

void print_trie(Node* root,char* str,int depth=0)
{
    if(depth==lcs)
        printf("%s\n",str);
    else
    {
        FOR(i,26)
        {
            if((root->ptr)[i]!=NULL)
                {
                        //printf("%c",'a'+i);
                        str[depth] = 'a' + i;
                        print_trie((root->ptr)[i],str,depth+1);
                }
        }
        delete root;
    }
}

int main()
{
    int t,m,n;

    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        fscanf(ifp,"%s",str1);
        fscanf(ifp,"%s",str2);
        m = strlen(str1);
        n = strlen(str2);

        /* LCS */
        //vector<pair<int,int> > b[m+1][n+1];
        int c[m+1][n+1];
        int** b = (int**)malloc(sizeof(int*)*(m+1));

        FOR(i,m+1)
            b[i] = (int*)malloc(sizeof(int)*(n+1));

        FOR(i,m+1)
            c[i][0] = 0;

        FOR(j,n+1)
            c[0][j] = 0;

            for(int i=1;i<m+1;i++)
            {
                for(int j=1;j<n+1;j++)
                    {

                        if(str1[i-1]==str2[j-1]){
                                    c[i][j] = c[i-1][j-1]+1;

                                    //b[i][j].push_back(Pd);
                                    b[i][j] = 2;

                                    if(c[i][j]==c[i-1][j])
                                           b[i][j]+=1;
                                    if(c[i][j]==c[i][j-1])
                                           b[i][j]+=4;
                            }
                        else
                        {
                            if(c[i-1][j]>c[i][j-1])
                                {
                                    c[i][j] = c[i-1][j];
                                    b[i][j]=1;
                                }
                            else if(c[i][j-1]>c[i-1][j])
                                {
                                    c[i][j] = c[i][j-1];
                                    b[i][j] = 4;
                                }
                            else
                            {
                                c[i][j] = c[i][j-1];
                                b[i][j] = 5;
                            }
                        }
                    }
                }

       //print(b,m+1,n+1);
       //cout<<"\n\n";

       lcs = c[m][n];
       char* str = (char*)malloc(sizeof(char)*MAX);
       str[lcs]='\0';
       Node* root =  new Node();
       solve(b,m,n,str,root);
       //print_trie(root,str);

       FOR(i,m+1)
            delete b[i];

        /* Print trie */
        delete b;
        delete str;
        delete root;
    }

    return 0;
}

