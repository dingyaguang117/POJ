#include <iostream>
#include <list>
#include <string.h>
#include <stack>
using namespace std;

#define MAXN 10005
list<int> Map[MAXN];
stack<int> STACK;
//Catagory保存1-N下标点的组号
//CNUM保存各组的个数
//OUTNUM保存各组的出度
int LOW[MAXN],DFN[MAXN],Catagory[MAXN],CNUM[MAXN],OUTNUM[MAXN];
bool instack[MAXN];
int N,M,CUR,NUM;


void tarjan(int v)
{
	int i;
	CUR++;
	LOW[v]=DFN[v]=CUR;
	instack[v]=true;
	STACK.push(v);
	list<int>::iterator it=Map[v].begin();
	for(;it!=Map[v].end();++it)
	{
		if(DFN[*it]==0)
		{
			tarjan(*it);
			if(LOW[*it]<LOW[v])
				LOW[v]=LOW[*it];
		}else if(instack[*it] && DFN[*it]<LOW[v])
		{
			LOW[v]=DFN[*it];
		}
	}
	if(DFN[v]==LOW[v])
	{
		NUM++;
		do
		{
			i=STACK.top();
			STACK.pop();
			instack[i]=false;
			Catagory[i]=NUM;
			CNUM[NUM]++;
		}
		while(i!=v);
	}
}

void GetSCC()
{
	memset(LOW,0,sizeof(LOW));memset(CNUM,0,sizeof(CNUM));
	memset(DFN,0,sizeof(DFN));memset(OUTNUM,0,sizeof(OUTNUM));
	memset(Catagory,0,sizeof(Catagory));
	memset(instack,0,sizeof(instack));
	CUR=0,NUM=0;

	int i,j;
	for(i=1;i<=N;++i)
	{
		if(!DFN[i])
			tarjan(i);
	}
}

int Calc()
{
	int i,n0=0,ans;
	list<int>::iterator it;
	for(i=1;i<=N;++i)
	{
		for(it=Map[i].begin();it!=Map[i].end();++it)
		{
			if(Catagory[*it] != Catagory[i])
				OUTNUM[Catagory[i]]++;
		}
		
	}
	for(i=1;i<=NUM;++i)
	{
		if(OUTNUM[i]==0) {n0++;ans=CNUM[i];}
	}
	if(n0>1) return 0;
	else return ans;
}

int main()
{
	int i,j,a,b; 
	cin>>N>>M;
	for(i=0;i<M;++i)
	{
		cin>>a>>b;
		Map[a].push_back(b);
	}
	GetSCC();

	cout<<Calc()<<endl;

}