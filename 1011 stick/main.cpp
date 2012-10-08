#include <stdio.h>
#include <string.h>

int N,A[64];
bool choosed[64];

bool dfs(int pos,int len)
{
	int i;
	bool r;
	if(A[pos] > len ) return false;
	choosed[pos] =true;
	if(A[pos] == len) return true;

	for(i=pos+1;i<N;++i)
	{
		if(!choosed[i])
		{
			if(dfs(i,len-A[pos]))
				return true;
		}
	}
	choosed[pos] =false;
	return false;
}

bool getone(int cur,int len)
{
	if(choosed[cur]) return true;
	return dfs(cur,len);
}

bool can(int len)
{
	int i;
	memset(choosed,0,sizeof(choosed));
	for(i=0;i<N;++i)
	{
		if(!getone(i,len)) return false;
	}
	return true;
}

int calc()
{
	int maxlen=0,sumlen=0,i;
	for(i=0;i<N;++i)
	{
		if(A[i]>maxlen) maxlen=A[i];
		sumlen+=A[i];
	}

	for(i=maxlen;i<=sumlen;++i)
	{
		if(sumlen%i) continue;
		if(can(i)) return i;
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d",&N),N)
	{
		for(i=0;i<N;++i) scanf("%d",A+i);
		printf("%d\n",calc());
	}
}