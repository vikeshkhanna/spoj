#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define INPUT "input"
#define MAXN 1000000
#define MAXM 1000000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
struct Node
{
    int count, low,high;
    bool toggle;
    Node* left, *right;
};

Node* create_tree(int low, int high)
{
    Node* root = (Node*)malloc(sizeof(struct Node));
    root->low = low;
    root->high = high;
    root->count = high-low + 1;
    root->toggle=false;

   if(low<high){
                int mid = (low+high)/2;
                root->left = create_tree(low,mid);
                root->right = create_tree(mid+1,high);
            }
    return root;
}

void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<"("<<root->low<<","<<root->high<<"): "<<root->count<<endl;
        inorder(root->right);
    }
}

int main()
{
    int n,m, a[MAXN];
    fscanf(ifp,"%d%d",&n,&m);
    Node* root = create_tree(0,n-1);
    //inorder(root);

    FOR(i,m){


    }

   delete root;
    return 0;
}


