#include <string>
#include <cstdio>


using namespace std;

char c[2005];
bool dp[2005][2005];

bool work(int a,int b)
{
	if (a>=b) return false;
	if(c[a]<c[b]) return false;
	if (c[a]>c[b]) return true;
	return work(a+1,b-1);
}

int main()
{

	int N,i,a=0,b,count=0;

	scanf("%d",&N);

	for (i=0;i<N;++i)
	{
		getchar();
		scanf("%c",c+i);
	}

	b=N-1;
	while(a<=b)
	{
		if (work(a,b))
		{
			printf("%c",c[b--]);
		}else
			printf("%c",c[a++]);

		if (!(++count%80))
		{
			printf("\n");
		}
	}
	if ((count%80))
	printf("\n");
}