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
#define MAX 10000000
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;


typedef unsigned int uint;

#define WHITE 0
#define GRAY 1
#define BLACK 2

unsigned int a[MAX];

//FILE *ifp = fopen("input.txt","r");
FILE *ifp = stdin;
//FILE *ofp = stdout;
//FILE *ofp = fopen("output.txt","w+");

/*
 * @author: Vikesh Khanna
 */
unsigned int f(unsigned int a[MAX], unsigned int x)
{
    //cout<<x<<endl;
    //system("pause");
    if(x<MAX && a[x]>0) 
             return a[x];
    
    uint org = x;
    unsigned int cnt = 0;
    
    while(x>=1)
    {
               if(x<MAX && a[x]>0) 
               {
                        cnt += a[x];
                        break;         
               }
               
               if(x&1) cnt +=2, x = (3*x+1)>>1;
               else cnt+=1, x >>=1;                        
    }
    
    if(org<MAX) a[org] = cnt;
    return cnt;   
   
}

/*Range tree for n values */
struct Node
{
       Node *left, *right, *p;
       uint low, high, val;
       
       Node(){
              left = right = p = NULL;
              val = 0;
       }
}; 

Node* construct(uint low, uint high, Node* parent = NULL)
{
     Node* root = new Node();
     root->p = parent;
     
     if(high==low){
                     root->low = low;
                     root->high = high;
                     root->val = a[low];
                     //cout<<root->val<<endl;
                     //system("Pause");
     }
     else{
                   root->low = low;
                   root->high = high;
                        
                   uint mid = (high+low)/2;  
                   root->left = construct(low,mid,root);
                   root->right = construct(mid+1,high,root);
                   root->val = max(root->left->val,root->right->val);
                   //cout<<"Setting : "<<root->val;
                   //system("pause");
     }
     
     return root;
}

void printnode(Node* root)
{
     cout<<"("<<root->low<<","<<root->high<<","<<root->val<<")"<<endl;              
}

void inorder(Node* root)
{
     if(root!=NULL){
                      inorder(root->left);
                      printnode(root);         
                      inorder(root->right);
     }     
}

//query the tree
unsigned int solve(Node* root, int low, int high)
{
      if(root->low>=low && root->high<=high)
      {      
             //printnode(root);
             return root->val;
      }
      else if(high < root->low || low > root->high)
      {
             //cout<<"rejecting: "; printnode(root);
             return 0;
      }
      else
      {
          //printnode(root);
          //system("pause");
          return max(solve(root->left, low, high),solve(root->right,low,high));          
      }
}

int main()
{
memset(a,0,sizeof(int)*MAX);
a[1] = 1;

FORS(s,2,1000000)
{
  f(a,s);
}

//FORS(i,1,500) printf("%d: %u\n",i,a[i]);           

Node* root = construct(1,1000000-1);
//inorder(root);

unsigned i, j;

while(fscanf(ifp,"%u%u",&i,&j)!=EOF)
{
    
    unsigned int l = min(i,j), h=max(i,j);
    printf("%u %u %u\n",i,j,solve(root,l,h));                                                                  
}

//dfs(a);


system("Pause");
return 0;
}
