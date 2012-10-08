#include <stdio.h>
#include <string.h>
int dp[11][11];
int N,M;
int f(int m,int n)
{ if(m<0)
   return 0;
  if(m==0||n==1)
   return 1;
  return f(m-n,n)+f(m,n-1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&M,&N);
		printf("%d\n",f(M,N));
	}
}