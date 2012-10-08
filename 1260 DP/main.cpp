#include <stdio.h>
#include <string.h>
#define MAXN 101

int data[MAXN][2];
int dp[MAXN][MAXN];

int calc(int a,int b)
{
	int i,r,min=0x7FFFFFFF,sum=0;
	if(dp[a][b]) return dp[a][b];
	if(a==b) return (data[a][0]+10)*data[a][1];

	for(i=a;i<b;++i)
	{
		if((r=calc(a,i)+calc(i+1,b))<min)
			min=r;
	}
	for(i=a;i<=b;++i)
	{
		sum+=data[i][0];
	}
	if((sum+10)*data[b][1] < min) min=(sum+10)*data[b][1];
	return dp[a][b]=min;
}

int main()
{
	int T,N,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;++i)
			scanf("%d%d",data[i],data[i]+1);
		memset(dp,0,sizeof(dp));
		printf("%d\n",calc(0,N-1));
	}

}