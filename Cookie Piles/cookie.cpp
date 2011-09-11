#include<stdio.h>

int main()
{
int t,n,a,d;
scanf("%d",&t);

for(int T=0;T<t;T++){

	scanf("%d%d%d",&n,&a,&d);

	int prod = n*(2*a + (n-1)*d);
	prod /=2;
	printf("%d\n",prod);

}

return 0;
}
