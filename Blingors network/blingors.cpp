#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define parent(i) (int)((i-1)/2)
#define left(i) 2*i+1
#define right(i) 2*i+2

#define INPUT "input"
#define MAX 10
#define MAXN 10000
#define LARGE 4294967295U
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef unsigned int uint;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;

class Minheap
{
        public:
            int size,n, *back;
            uint *a, *key;

            Minheap(uint* key, int* back,int n)
            {
                    size = 0;
                    this->key= key;
                    this->back = back;
                    this->n= n;
                    a = (uint*)malloc(sizeof(uint)*n);
                    //this->admin = admin;
                    build_heap();
            }

            ~Minheap()
            {
                delete a;
            }

            void build_heap()
            {
                FOR(i,n){
                        a[i] = i;
                        back[i] = i;
                        size++;
                    }

               for(int i=size/2;i>=0;i--)
                    min_heapify(i);
            }

            void min_heapify(int i)
            {
                int left, right, smallest;

                while(i<size){
                        smallest= i;
                        left = left(i);
                        right = right(i);

                        if(left<size && key[a[left]]<key[a[smallest]]) smallest = left;
                        if(right<size && key[a[right]]<key[a[smallest]]) smallest = right;

                        if(smallest!=i)
                        {
                            int temp = a[i];
                            a[i]  = a[smallest];
                            a[smallest] = temp;
                            back[a[i]] = i;
                            back[a[smallest]] = smallest;
                        }
                        else break;
                        i=smallest;
                    }
            }

            void decrease_key(int i,uint val) //i is the (0.26) vertex number
            {
                int index = back[i];
                //cout<<"back found: "<<back[i]<<endl;
                if(key[a[index]]<=val) return ;

                    int smallest = index,p = parent(smallest);
                    key[a[index]]=val;

                    while(smallest>0 && key[a[p]]>key[a[smallest]])
                        {
                            //cout<<" "<<smallest<<" "<<p<<endl;
                                int temp = a[p];
                                a[p] = a[smallest];
                                a[smallest]=temp;
                                back[a[smallest]]=smallest;
                                back[a[p]]= p;
                                smallest = p;
                                p = parent(smallest);
                            }
            }


            int extract_min()
            {
                int ret = a[0];
                a[0] = a[size-1];
                a[size-1] = ret;
                back[a[0]] = 0;
                back[a[size-1]] = size-1;
                //back[ret] = size;
                size--;
                min_heapify(0);
                //admin[ret]=true;
                return ret;
            }

            bool empty()
            {
                    return size==0;
            }

            void print()
            {
                cout<<"******************"<<endl;
                    FOR(i,size)
                        cout<<"("<<a[i]<<","<<key[a[i]]<<","<<back[a[i]]<<","<<")"<<endl;
                cout<<"******************"<<endl;
            }

};

int main()
{
    int t,p,v,n,back[MAXN];
    uint c, key[MAXN];
    char str[MAX+1];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&n);
            vector<pair<int,uint> > adj[n];

            FOR(i,n){
                fscanf(ifp,"%s",str);
                fscanf(ifp,"%d",&p);


                FOR(u,p){
                       fscanf(ifp,"%d %u",&v,&c);
                       pair<int,uint> P(v-1,c);
                       adj[i].push_back(P);
                }
            }

             /*FOR(i,n){
                FOR(j,adj[i].size())
                    cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<")";
                cout<<endl;
            }*/

            FOR(i,n)
                    key[i] = LARGE;
            key[0]=0;

            uint sum=0;
            Minheap H(key,back,n);
            /*Prim's algo*/
            while(!H.empty())
            {
                int k = H.extract_min(), len = adj[k].size();
                sum += (uint)key[k];
                //H.print();
                FOR(i,len)
                    H.decrease_key(adj[k][i].first,adj[k][i].second);
                //H.print();
            }

            printf("%u\n",sum);
            /*Minheap H(key,back,n);
            H.print();
            H.extract_min();
            H.print();*/
    }
    //printf("%d\n",(uint)pow(2,32)-1);
    return 0;
}


