#include <stdio.h>

bool Map[101][101],can[101][101];
int N,M;
int main()
{
	int i,j,k,a,b;
	scanf("%d%d",&N,&M);
	for (i=0;i<M;++i)
	{
		scanf("%d%d",&a,&b);
		Map[a][b]=true;
		can[a][b]=true;
	}
	for (k=1;k<=N;++k)
	{
		for(i=1;i<=N;++i)
		{
			for (j=1;j<=N;++j)
			{
				if (can[i][k]&&can[k][j])
				{
					can[i][j]=true;
				}
			}
		}
	}
	int r=0;
	for (i=1;i<=N;++i)
	{
		int a=0;
		for (j=1;j<=N;++j)
		{
			if (can[i][j])
			{
				a++;
			}
		}
		for (j=1;j<=N;++j)
		{
			if (can[j][i])
			{
				a++;
			}
		}
		if (a==N-1)
		{
			r++;
		}
	}
	printf("%d\n",r);
}