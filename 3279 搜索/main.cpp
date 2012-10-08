#include <iostream>
using namespace std;

#define MAXN 16
#define setbit(A,n) ((A)|=(1<<(n)))
#define removebit(A,n) ((A)&=(~(1<<(n))))
#define getbit(A,n) (((A)>>(n))&1)
int Map[MAXN],tmp[MAXN],stdm[MAXN];
int M,N;

int doComfirm()
{
	int i,j,num=0,ori;
	for(j=0;j<N;++j)
	{
		if(getbit(tmp[0],j))
			num++;
	}
	for(i=1;i<M;++i)
	{
		for(j=0;j<N;++j)
		{
			ori=0;
			ori^=getbit(Map[i-1],j);
			ori^=getbit(tmp[i-1],j);
			if(j>0)
				ori^=getbit(tmp[i-1],j-1);
			if(j<N-1)
				ori^=getbit(tmp[i-1],j+1);
			if(i>1)
				ori^=getbit(tmp[i-2],j);
			if(ori)
			{
				setbit(tmp[i],j);
				num++;
			}
			else
				removebit(tmp[i],j);
		}
	}
	//测试可行性
	ori=0;
	ori^=getbit(tmp[M-1],0);
	ori^=getbit(Map[M-1],0);
	if(M>1) ori^=getbit(tmp[M-2],0);
	if(N>1) ori^=getbit(tmp[M-1],1);
	if(ori)
		return -1;
	ori=0;
	ori^=getbit(tmp[M-1],N-1);
	ori^=getbit(Map[M-1],N-1);
	if(M>1) ori^=getbit(tmp[M-2],N-1);
	if(N>1) ori^=getbit(tmp[M-1],N-2);
	if(ori)
		return -1;
	
	for(j=1;j<N-1;++j)
	{
		ori=getbit(tmp[M-1],j)^getbit(tmp[M-1],j-1)^getbit(tmp[M-1],j+1)^getbit(Map[M-1],j);
		if(M>1)ori^=getbit(tmp[M-2],j);
		if(ori) return -1;
	}
	return num;
}

void doPrint()
{
	int i,j;
	for(i=0;i<M;++i)
	{
		for(j=0;j<N-1;++j)
		{
			cout<<getbit(stdm[i],j)<<" ";
		}
		cout<<getbit(stdm[i],N-1)<<endl;
	}
}
int main()
{
	int i,j,num,min;
	cin>>M>>N;
	for(i=0;i<M;++i)
	{
		for(j=0;j<N;++j)
		{
			if(cin>>num,num==1)
				setbit(Map[i],j);
		}
	}
	int lim= (1<<M);
	min=1000000;
	//开始枚举
	for(i=0;i<lim;++i)
	{
		tmp[0]=i;
		num=doComfirm();
		if(num==-1) continue;
		if(num<min)
		{
			min=num;
			for(j=0;j<M;++j)
				stdm[j]=tmp[j];
		}
	}
	if(min==1000000)
		cout<<"IMPOSSIBLE\n";
	else
		doPrint();
	//cin>>num;
}