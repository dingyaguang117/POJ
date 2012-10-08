#include<stdio.h>
int main()
{
	int n,i,j,k,a[20][20];
	while(scanf("%d",&n)!=EOF)
	{
		k=1;
		for(i=0;i<(n+1)/2;++i)
		{
			for(j=0+i;j<n-i;++j)
			{
				a[j][i]=k;
				++k;
			}
			for(j=1+i;j<n-i;++j)
			{
				a[n-1-i][j]=k;
				++k;
			
			}
			for(j=n-2-i;j>=0+i;--j)
			{
				a[j][n-1-i]=k;
				++k;

			}
			for(j=n-2-i;j>=1+i;--j)
			{
				a[i][j]=k;
				++k;
			}
			
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
				prinf("%4d",a[i][j]);
			printf("\n");
		}



			
	}
	return 0;
}