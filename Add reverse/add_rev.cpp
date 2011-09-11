#include<iostream>
#include<fstream>
#include <stdio.h>
#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

//FILE* ifp = fopen(INPUT,"r");
FILE* ifp = stdin;

unsigned long reverse(unsigned long n)
{
    while(n%10==0)
            n=n/10;

    unsigned long pow=1,num=0;

    while(n>0)
    {
            num = num*10 + n%10;
            n = n/10;
    }
    return num;
}

int main()
{
    int t;
    unsigned long n1,n2;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&n1);
            fscanf(ifp,"%d",&n2);

            printf("%u\n",reverse(reverse(n1) + reverse(n2)));
    }

    return 0;
}

