#include <iostream>
#include <queue>
#include <string>
#define  MAXN 362881

using namespace std;

struct node
{
	unsigned __int8 st[3][3];
	int x,y,n;
}Q[MAXN];

int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int nCan[3][3]=
{
	2,3,2,
	3,4,3,
	2,3,2
};

int dirCan[3][3][4]=
{
	{{2,4},{2,3,4},{2,3}},{{1,2,4},{1,2,3,4},{1,2,3}},{{1,4},{1,3,4},{1,3}}
};

int pre[MAXN];
int dir[MAXN];
bool HASH[MAXN];

int getHash(unsigned __int8 *a)
{
	int i,j,t,r=0;;
	for (i=1;i<9;++i)
	{
		t=0;
		for (j=0;j<i;++j)
		{
			if (a[j]>a[i]) t++;
		}
		r+=fac[i]*t;
	}
	return r;
}

void swap(unsigned __int8 &a,unsigned __int8 &b)
{
	unsigned __int8 t;
	t=a;
	a=b;
	b=t;
}

bool check(unsigned __int8 *a)
{
	unsigned __int8 i;
	for (i=0;i<9;++i)
	{
		if (a[i]!=i+1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int front=0,end=0;
	int i,j;
	char c;
	bool flag=0;

	//输入数据
	for (i=0;i<3;++i)
	{
		for (j=0;j<3;++j)
		{
			cin>>c;
			if (c=='x')
			{
				Q[front].x=i;
				Q[front].y=j;
				Q[front].n=0;
				Q[front].st[i][j]=9;
			}else
			{
				Q[front].st[i][j]=c-'0';
			}
		}
	}
	end++;
	
	HASH[getHash((unsigned __int8 *)Q[front].st)]=1;
	
	//开始搜索
	while (front!=end)
	{
		for (i=0; i<nCan[ Q[front].x ][ Q[front].y ] ;++i)
		{
			pre[end]=front;
			Q[end].n=Q[front].n+1;
			Q[end].st[0][0]=Q[front].st[0][0];
			Q[end].st[0][1]=Q[front].st[0][1];
			Q[end].st[0][2]=Q[front].st[0][2];
			Q[end].st[1][0]=Q[front].st[1][0];
			Q[end].st[1][1]=Q[front].st[1][1];
			Q[end].st[1][2]=Q[front].st[1][2];
			Q[end].st[2][0]=Q[front].st[2][0];
			Q[end].st[2][1]=Q[front].st[2][1];
			Q[end].st[2][2]=Q[front].st[2][2];


			switch(dirCan[ Q[front].x ][ Q[front].y ][i])
			{
			case 1:	//up
				
				dir[end]=1;
				Q[end].x=Q[front].x-1;
				Q[end].y=Q[front].y;
				swap(Q[end].st[ Q[end].x ][ Q[end].y ],Q[end].st[ Q[end].x+1 ][ Q[end].y ]);
				break;
			case 2:	//down
				dir[end]=2;
				Q[end].x=Q[front].x+1;
				Q[end].y=Q[front].y;
				swap(Q[end].st[ Q[end].x ][ Q[end].y ],Q[end].st[ Q[end].x-1 ][ Q[end].y ]);
				break;
			case 3:
				dir[end]=3;
				Q[end].x=Q[front].x;
				Q[end].y=Q[front].y-1;
				swap(Q[end].st[ Q[end].x ][ Q[end].y ],Q[end].st[ Q[end].x ][ Q[end].y+1 ]);
				break;
			case 4:
				dir[end]=4;
				Q[end].x=Q[front].x;
				Q[end].y=Q[front].y+1;
				swap(Q[end].st[ Q[end].x ][ Q[end].y ],Q[end].st[ Q[end].x ][ Q[end].y-1 ]);
				break;
			}
			
			if (check((unsigned __int8 *)Q[end].st))
			{
				flag=1;
				break;
			}

			j=getHash((unsigned __int8 *)Q[end].st);
			if (HASH[j])
			{
				continue;
			}

			HASH[j]=1;
			end++;

		}
		if (flag)
		{
			break;
		}
		front++;
	}
	
	string s;
	i=end;
	while (i)
	{
		if (s.size())
		{
			s+=" ";
		}
		switch(dir[i])
		{
		case 1:
			s+="u"; break;
		case 2:
			s+="d";	break;
		case 3:
			s+="l";	break;
		case 4:
			s+="r";	break;
		}

		i=pre[i];;
	}

	for (i=s.size()-1;i>=0;--i)
	{
		cout<<s[i];
	}

	return 0;
}
