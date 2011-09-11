#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "test"
#define MAX 20
#define MAXN 30000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
class Node
{
        public:
        int val;
        Node* ptr[26];

        Node(int val=-1){
                this->val = val;
                FOR(i,26)
                        ptr[i] = NULL;
        }

};

int merge(int* a,int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;

	int count=0, L[n1+1], R[n2+1];

	FOR(i,n1) L[i] = a[p+i];
	FOR(i,n2) R[i] = a[q+i+1];

	L[n1] = R[n2] =  L[n1-1] + R[n2-1];
	int i=0,j=0;

	for(int k=p;k<=r;k++){
                             if(L[i]<=R[j])
                                             a[k]=L[i++];
                             else
                             {
                                             a[k]=R[j++];
                                             count+=(n1-i);
                             }
	}
  //cout<<"Merge: "<<count<<endl;
  return count;
}

int num_inversions(int* a,const int p, const int r)
{
    int count=0;

   	if(p<r)
	{
		int q = (p+r)/2;
		count =  num_inversions(a,p,q) + num_inversions(a,q+1,r);
		count += merge(a,p,q,r);
	}
	 return count;
}


int main()
{
    int t,n, a[MAXN];
    char c;
    char str1[MAXN][MAX+1], str2[MAXN][MAX+1];
    Node* root = new Node();

    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        fscanf(ifp,"%d",&n);

        FOR(i,n)
                    fscanf(ifp,"%s",str1[i]);

        FOR(i,n)
                    fscanf(ifp,"%s",str2[i]);



        //cout<<str1[n-1]<<" "<<str2[n-1]<<endl;

        /* Add to Trie */
        FOR(i,n)
        {
            Node* temp = root;
            int len = strlen(str2[i]);

            FOR(j,len)
            {
                char c = str2[i][j];
                int index = c - 'a';

                if(temp->ptr[index]==NULL)
                        temp->ptr[index] = new Node();
                temp = temp->ptr[index];
            }
            temp->val = i;
        }

        FOR(i,n)
        {
                Node* temp = root;
                int len = strlen(str1[i]);
                //cout<<"i: "<<i<<"str: "<<str1[i]<<"len :"<<len<<endl;
                FOR(j,len)
                {
                    char c = str1[i][j];
                    int index = c - 'a';
                    temp = temp->ptr[index];
                }

                a[i] = temp->val;
                //temp->val = -1;
        }
        /*
        FOR(i,n)
            cout<<a[i]<<" ";
        cout<<endl;
        */
        printf("%d\n",num_inversions(a,0,n-1));
    }

    delete root;
    return 0;
}

