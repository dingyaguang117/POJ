#include <stdio.h>
int main()
{
	int T,N,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		a=N/2;
		b=N-a;
		printf("%d\n",a*(a-1)/2+b*(b-1)/2);
	}
}