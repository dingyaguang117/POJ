#include <stdio.h>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;
/*
int main()
{
	int N,i,j,ans,eq;
	int A[1001],B[1001],choosed[1001];
	while(scanf("%d",&N),N)
	{
		memset(choosed,0,sizeof(choosed));
		for (i=0;i<N;++i) scanf("%d",A+i);
		for (i=0;i<N;++i) scanf("%d",B+i);
		sort(A,A+N,greater<int>());
		sort(B,B+N,greater<int>());
		eq=ans=i=j=0;
		while(i<N && j<N)
		{
			if(A[i]>B[j]) {ans++;i++;j++;choosed[j-1]=1;}
			else {j++;}
		}
		j=0;
		while(i<N && j<N)
		{
			if(A[i]==B[j] && choosed[j]==0) {eq++;i++;j++;}
			else {j++;}
		}
		ans-=N-ans-eq;
		printf("%d\n",ans*200);
	}
}*/
/*
int main()
{
	int N,i,j,ans,eq,a1,a2,b1,b2;
	int A[1005],B[1005],choosed[1005];
	while(scanf("%d",&N),N)
	{
		memset(choosed,0,sizeof(choosed));
		for (i=0;i<N;++i) scanf("%d",A+i);
		for (i=0;i<N;++i) scanf("%d",B+i);
		sort(A,A+N,greater<int>());
		sort(B,B+N,greater<int>());
		eq=ans=i=j=0;
		a1=b1=0;a2=b2=N-1;
		while(a1<=a2)
		{
			if(A[a1]>B[b1])
			{
				ans++;
				a1++;b1++;
			}else if(A[a1]==B[b1])
			{
				if(A[a2]>B[b2])
				{
					a1++;b1++;
				}else if(A[a2]==B[b2])
				{
					if (A[a2]<B[b1])
					{
						ans--;
						b1++;
						a2--;
					}else
					{
						a1++;b1++;
					}

				}else
				{
					ans--;
					b1++;
					a2--;
				}
			}else
			{
				ans--;
				b1++;
				a2--;
			}
		}
		
		printf("%d\n",ans*200);
	}
}*/

int main()
{
	int N,i,j,ans,eq,a1,a2,b1,b2;
	int A[1005],B[1005],choosed[1005];
	while(scanf("%d",&N),N)
	{
		memset(choosed,0,sizeof(choosed));
		for (i=0;i<N;++i) scanf("%d",A+i);
		for (i=0;i<N;++i) scanf("%d",B+i);
		sort(A,A+N,greater<int>());
		sort(B,B+N,greater<int>());
		eq=ans=i=j=0;
		a1=b1=0;a2=b2=N-1;
		while(a1<=a2)
		{
			if(A[a1]>B[b1])
			{
				ans++;
				a1++;b1++;
			}else if(A[a1]==B[b1])
			{
				if(A[a2]>B[b2])
				{
					ans++;a2--;b2--;
				}else if(A[a2]==B[b2])
				{
					if (A[a2]<B[b1])
					{
						ans--;
						b1++;
						a2--;
					}else
					{
						a1++;b1++;
					}

				}else
				{
					ans--;
					b1++;
					a2--;
				}
			}else
			{
				ans--;
				b1++;
				a2--;
			}
		}

		printf("%d\n",ans*200);
	}
}