#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>

#define INPUT "input"
#define WALL '#'
#define FREE '-'
#define MAN '*'

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 100
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ifp = stdin;
int m,n;

void dfs_visit(const char hotel[MAX][MAX],short color[MAX][MAX],int r,int c,int& count)
{
    color[r][c] = GRAY;

    if(hotel[r][c]==MAN) count++;

    if(r>0 && color[r-1][c]==WHITE)
            dfs_visit(hotel,color,r-1,c,count);

    if(c>0 && color[r][c-1]==WHITE)
            dfs_visit(hotel,color,r,c-1,count);

    if(r<m-1 && color[r+1][c]==WHITE)
            dfs_visit(hotel,color,r+1,c,count);

    if(c<n-1 && color[r][c+1]==WHITE)
            dfs_visit(hotel,color,r,c+1,count);

    color[r][c]=BLACK;
}

void print(char arr[MAX][MAX])
{
    FOR(i,m){
        FOR(j,n)
            printf("%c ",arr[i][j]);
        printf("\n");
    }
}


void dfs(const char hotel[MAX][MAX],int& people, int& rooms)
{
    short color[MAX][MAX];
    int temp;


    FOR(i,m)
        FOR(j,n)
            if(hotel[i][j]==WALL)
                color[i][j]=BLACK;
            else
                color[i][j]=WHITE;

    rooms = 0, people = 0;
    FOR(i,m)
        FOR(j,n)
            if(color[i][j]==WHITE){
                    temp=0;
                    dfs_visit(hotel,color,i,j,temp);
                    people +=temp;
                    rooms++;
            }
}


int main()
{
    int t,people,rooms;
    char str[MAX], hotel[MAX][MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        fscanf(ifp,"%d %d",&m,&n);

        FOR(i,m){
                fscanf(ifp,"%s",str);
                FOR(j,n)
                    hotel[i][j] = str[j];
        }

        dfs(hotel,people,rooms);
        printf("%.2f\n",(float)people/rooms);
        //cout<<"people: "<<people<<"rooms: "<<rooms<<endl;

    }
    //delete a;
    return 0;
}



