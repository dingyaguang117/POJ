#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define  MAXN 101

using namespace std;
struct EDGE
{
	int a,b,w;
};

vector<EDGE> EDGES[MAXN];
bool steped[MAXN+1];
int dis[MAXN+1];
EDGE MST[MAXN+1],MST2[MAXN+1];
int N,M,cost;
int F[MAXN][MAXN];

void dfs(int start,int p)
{
	int i;
	steped[p]=true;
	for (i=1;i<=N;++i)
	{
		if (MST[i].a==p && !steped[i])
		{
			F[start][i]=F[start][p]>MST[i].w?F[start][p]:MST[i].w;
			dfs(start,i);
		}
		if (i==p && !steped[MST[i].a])
		{
			F[start][MST[i].a]=F[start][p]>MST[i].w?F[start][p]:MST[i].w;
			dfs(start,MST[i].a);
		}
	}
}

void dogetF()
{
	int i,j;

	for(i=1;i<=N;++i)
	{
		memset(steped,0,sizeof(steped));
		F[i][i]=0;
		dfs(i,i);
	}
}
bool inMST(EDGE t)
{
	if (MST[t.a].a==t.b || MST[t.b].a==t.a)
	{
		return true;
	}
	return false;
}

int calc()
{
	int i,j;
	int	minincrease=1000000000;
	for (i=1;i<=N;++i)
	{
		for (j=0;j<EDGES[i].size();++j)
		{
			if (!inMST(EDGES[i][j]))
			{
				if (EDGES[i][j].w-F[EDGES[i][j].a][EDGES[i][j].b] < minincrease)
				{
					minincrease = EDGES[i][j].w-F[EDGES[i][j].a][EDGES[i][j].b];
				}
			}
		}
	}
	return minincrease;
}


void doMST()
{
	int i,j;
	for (i=1;i<=N;++i) dis[i]=0x7fffffff;

	dis[1]=0;
	cost=0;
	memset(steped,0,sizeof(steped));
	for (i=0;i<N;++i)
	{
		int mindis=1000000000,nextp;
		for(j=1;j<=N;++j)
		{
			if(!steped[j] && mindis>dis[j])
			{
				mindis=dis[j];
				nextp=j;
			}
		}
		steped[nextp]=true;
		cost+=mindis;
		for(j=0;j<EDGES[nextp].size();++j)
		{
			if (!steped[EDGES[nextp][j].b] && dis[EDGES[nextp][j].b]>EDGES[nextp][j].w)
			{
				dis[EDGES[nextp][j].b]=EDGES[nextp][j].w;
				MST[EDGES[nextp][j].b].a=nextp;
				MST[EDGES[nextp][j].b].w=EDGES[nextp][j].w;
			}
		}
	}
}

int main()
{
	int T,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&N,&M);
		for(i=0;i<=N;++i) EDGES[i].clear();
		memset(steped,0,sizeof(bool)*N);

		for(i=0;i<M;++i)
		{
			EDGE one;
			scanf("%d%d%d",&one.a,&one.b,&one.w);
			EDGES[one.a].push_back(one);
			int t=one.a;one.a=one.b;one.b=t;
			EDGES[one.a].push_back(one);
		}

		doMST();

		dogetF();
		if (calc()>0)
		{
			printf("%d\n",cost);

		}else
			printf("Not Unique!\n");

	}
}