#include <stdio.h>
#include <math.h>
struct point
{
	int r,g,b;
}stdp[16];

double dis(point &a,point &b){
	return sqrt(double((a.r-b.r)*(a.r-b.r)+(a.g-b.g)*(a.g-b.g)+(a.b-b.b)*(a.b-b.b)));
}

int main()
{
	int i,min;
	for (i=0;i<16;++i)
	{
		scanf("%d%d%d",&stdp[i].r,&stdp[i].g,&stdp[i].b);
	}
	point in;
	while (~scanf("%d%d%d",&in.r,&in.g,&in.b))
	{
		if (in.r==-1)
		{
			break;
		}
		double dist=1e10,t;
		for (i=0;i<16;++i)
		{
			if ((t=dis(in,stdp[i]))<dist)
			{
				dist=t;
				min=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",in.r,in.g,in.b,stdp[min].r,stdp[min].g,stdp[min].b);
	}
}