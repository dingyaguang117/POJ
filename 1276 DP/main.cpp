#include <stdio.h>
#include <string.h>
#define MAXN 100001

bool can[MAXN];
int N,MAX,LEN;
int C[10005];
int main()
{
	int i,j,a,b;
	while(~scanf("%d",&MAX))
	{
		scanf("%d",&N);
		LEN=0;
		for(i=0;i<N;++i)
		{
			scanf("%d%d",&a,&b);
			int sum=0;
			for(j=1;j<a;j*=2)
			{
				if(sum+j>a) break;
				C[LEN++]=b*j;
				sum+=j;
			}
			C[LEN++]=(a-sum)*b;
		}
		memset(can,0,sizeof(bool)*(MAX+1));
		can[0]=true;
		for(i=0;i<LEN;++i)
		{
			for(j=MAX;j-C[i]>=0;--j)
			{
				if(can[j-C[i]]) can[j]=true;
			}
		}
		int r=0;
		for(i=MAX;i>=0;--i)
		{
			if(can[i]) {r=i;break;}
		}
		printf("%d\n",r);
	}
}