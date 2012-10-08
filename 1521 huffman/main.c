#include <stdio.h>
int main()
{
	int m,i,j;
	int a[31][31];
	for(i=0;i<31;++i)
		a[i][0]=a[i][i]=1;
   for(i=2;i<30;++i)
		for(j=1;j<i;++j)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	while(scanf("%d",&m),m)
	{
		for(i=0;i<m;++i)
		{
			for(j=0;j<i;++j)
				printf("%d ",a[i][j]);
			printf("%d\n",a[i][j]);
		}
		printf("\n");
	}
		return 0;
            

	

}