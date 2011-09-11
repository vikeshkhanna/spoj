#include<stdio.h>
#include<string.h>
#include<cmath>
#define FOR(i,n) for(int i=0;i<n;i++)
int main()
{
    int t;
    char a[1001];
    long long b;
    short h[10] = {1,1,4,4,2,1,1,4,4,2},d,c,x;
    scanf("%d",&t);

    FOR(T,t)
    {
        scanf("%s%lld",a,&b);
        d = a[strlen(a)-1] - '0', c = h[d];
        //printf("%d\n",d);
        //printf("%s\n",a);
        if(!strcmp(a,"0") && b!=0)
            printf("0\n");
        else if(b==0)
            printf("1\n");
        else
        {
            short r = b%c;
            x = (r==0?c:r);
            printf("%d\n",(int)pow(d,x)%10);
        }
    }
    return 0;
}
