#include<stdio.h>
#include<math.h>
double k[500000];
int main()
{
	int n,max,v[100],i,j;
	double sum=0,min,val;
	scanf("%d %d",&n,&max);
	for(i=0;i<n;++i)
		scanf("%d",&v[i]);
	for(i=1;i<=max;++i)
		if(i<v[0])
			k[i]=0;
		else
		{
			min=i;
			for(j=0;i-v[j]>0&&j<n;++j)
				if(min>k[i-v[j]]+1)
					min=k[i-v[j]]+1;
			if(min==1&&i!=1&&i-v[j]!=0)
				min=0;
			if(i-v[j]==0)
				if(min>1)
					min=1;
			k[i]=min;
			sum+=1/min;
		}
		val=sum/(log(double(n+1))/log(2.0)*log(max+1.71828));
		printf("%.4f\n",val);
		return 0;

}