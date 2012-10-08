#include <stdio.h>
#include <algorithm>
using namespace std;

int len[20001];
8
int main()
{
	int N,S,i,j,sum=0;
	scanf("%d%d",&N,&S);
	for(i=0;i<N;++i)
	{
		scanf("%d",len+i);
	}
	sort(len,len+N);
	for(i=0;i<N-1;++i)
	{
		int num=upper_bound(len,len+N,S-len[i]);
		if (num-1>=len[i])
		{
			sum+=num-1;
		}else
			sum+=num;
	}
	printf("%d\n",sum);
}