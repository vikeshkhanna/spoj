#include <cstdio>

#include <algorithm>
using namespace std;

int f(int i)
{
int cnt = 1;

while(i != 1) {
if(i&1) cnt+=2,i=(3*i+1)>>1;
else ++cnt,i=i>>1;
}

return cnt;
}

int main()
{
int i, j, a;
int mx;

while(scanf("%d%d", &i, &j)!=EOF) {
mx = -1;
for(a=min(i,j); a<=max(i,j); ++a)
mx = max(mx, f(a));
printf("%d %d %d\n", i, j, mx);
}

return 0;
}
