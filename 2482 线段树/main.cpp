/*成段更新 查询最大*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


#define LL(i) (i<<1)
#define RR(i) (i<<1|1)
#define MID(a,b) ((a+b)>>1)



#define MAXN 100005
struct node
{
	int begin,end;
	__int64 value;
	__int64 add;
};

struct edge
{
	__int64 y;
	__int64 left,right;
	__int64 value;
};

node ST[MAXN*4];
int N,W,H;
__int64 A[MAXN*2];
__int64 X[MAXN*4],Xcount;
edge E[MAXN*4];
__int64 Ecount,Ans;


bool cmp(const edge& a,const edge& b)
{
	if(a.y==b.y)
		return a.value<b.value;
	return a.y<b.y;
}

void update(const __int64 &v)
{
	if(v>Ans) Ans=v;
}

__int64 initST(int cur,int begin,int end)
{
	int mid=(begin+end)>>1;
	ST[cur].begin=begin;
	ST[cur].end=end;
	if(begin==end)
	{
		return ST[cur].value=A[begin];
	}else
	{
		return ST[cur].value=max(initST(cur<<1,begin,mid),initST(cur<<1|1,mid+1,end));
	}
}

__int64 Query(int cur,int pos1,int pos2)
{
	int mid=(ST[cur].begin+ST[cur].end)>>1;
	if(pos1<=ST[cur].begin && ST[cur].end<=pos2)
	{
		return ST[cur].value+ST[cur].add;
	}
	
	if (ST[cur].add)
	{
		ST[cur].value+=ST[cur].add;
		ST[cur<<1].add+=ST[cur].add;
		ST[cur<<1|1].add+=ST[cur].add;
		ST[cur].add=0;
	}
	if(pos1>mid)
		return Query(cur<<1|1,pos1,pos2);
	if(pos2<=mid)
		return Query(cur<<1,pos1,pos2);
	return max(Query(cur<<1,pos1,mid),Query(cur<<1|1,mid+1,pos2));
}

void Add(int cur,int pos1,int pos2,int num)
{
	if(pos1<=ST[cur].begin && ST[cur].end<=pos2)
	{
		ST[cur].add+=num;
		return;
	}
	if (ST[cur].add)
	{
		ST[cur<<1].add+=ST[cur].add;
		ST[cur<<1|1].add+=ST[cur].add;
		ST[cur].add=0;
	}
	int a=((pos1>ST[cur].begin)?pos1:ST[cur].begin);
	int b=((ST[cur].end<pos2)?ST[cur].end:pos2);

	int mid=(ST[cur].begin+ST[cur].end)>>1;
	if (pos2>mid)
		Add(cur<<1|1,pos1,pos2,num);
	if (pos1<=mid)
		Add(cur<<1,pos1,pos2,num);
	
	ST[cur].value=max(ST[LL(cur)].add+ST[LL(cur)].value,ST[RR(cur)].add+ST[RR(cur)].value);
	
}
void solve()
{
	int i,a,b;
	memset(A,0,sizeof(A));
	initST(1,1,Xcount);

	for(i=0;i<Ecount;++i)
	{
		a=lower_bound(X,X+Xcount,E[i].left)-X+1;
		b=lower_bound(X,X+Xcount,E[i].right)-X+1;
		Add(1,a,b,E[i].value);
		update(ST[1].value+ST[1].add);
	}
}

void work()
{
	__int64 i,y,x,v;

	while(~scanf("%d%d%d",&N,&W,&H))
	{
		Xcount=0;
		Ecount=0;
		Ans=0;

		for(i=0;i<N;++i)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&v);

			X[Xcount++]=x;
			X[Xcount++]=x+W-1;

			E[Ecount].left=x;
			E[Ecount].right=x+W-1;
			E[Ecount].y=y;
			E[Ecount].value=v;

			Ecount++;

			E[Ecount].left=x;
			E[Ecount].right=x+W-1;
			E[Ecount].y=y+H;
			E[Ecount].value=-v;

			Ecount++;

		}

		sort(X,X+N*2);
		Xcount=unique(X,X+N*2)-X;

		sort(E,E+N*2,cmp);

		solve();

		printf("%I64d\n",Ans);
	}
}

int main()
{

	work();
	
}