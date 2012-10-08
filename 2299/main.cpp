#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


#define typev int // type of res 
typev ar[500005]; // index: 1 ~ N 
int lowb(int t) { return t & (-t) ; } 
void add(int i, typev v) { 
	for ( ; i < 500005; ar[i] += v, i += lowb(i)); 
} 
typev sum(int i) { 
	typev s = 0; 
	for ( ; i > 0; s += ar[i], i -= lowb(i)); 
	return s; 
} 



pair<int,int> A[500005];
int B[500005];

bool cmp(const pair<int,int>& a,const pair<int,int> &b)
{
	return a.first<b.first;
}

int main()
{
	int N,i,j;
	long long ans;

	while (scanf("%d",&N),N)
	{
		for (i=0;i<N;++i)
		{
			scanf("%d",&A[i].first);
			A[i].second=i;
		}
		stable_sort(A,A+N,cmp);
		for (i=0;i<N;++i)
		{
			B[A[i].second]=i+1;
		}

		ans=0;
		memset(ar,0,sizeof(ar));
		for (i=0;i<N;++i)
		{
			add(B[i],1);
			ans+=i-sum(B[i]-1);
			//printf("%d ",B[i]);
		}
		memset(ar,0,(N+3)*sizeof(int));
		printf("%I64d\n",ans);
	}
}