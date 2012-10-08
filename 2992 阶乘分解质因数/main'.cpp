#include <stdio.h>
#include <math.h>
#include <string.h>

int fenjie[100];
int N,K;

#define MAX 438
int p[MAX];
int prime[MAX];
int primenum,num;
int creatprime2(int lim){//��˵�е�2��ѹ��ɸѡ����
	int sievelimit = ( sqrt(lim * 1.0) - 1 ) / 2;//ֻ��ɸ��һ��
	int maxindex = ( lim - 1 ) / 2;
	int n,t,k;
	for(n = 1; n <= sievelimit; n++){
		if(p[n] == 0){
			t = 2*n + 1;//ÿ�α�ʾ������2n+1
			for(k = 2*n*(n+1); k <= maxindex; k += t)//��2n(n+1)��ʼ
				p[k] = 1;
		}
	}
	prime[0] = 2;
	primenum = 1;
	for(n = 1; n <= maxindex ;n++){
		if(p[n]==0)
			prime[primenum++] = 2*n+1;//p[n]==0��ʾ����2*n+1������
	}
	return primenum;
}

void fenjiejiecheng(int n,int op)	//op==1 �� op==-1��
{
	int i;
	for(i=0;i<num;++i)
	{
		int t=n;
		while(t!=0)
		{
			t/=prime[i];
			fenjie[i]+= op*t;
		}
	}
}

int main()
{
	int i;
	creatprime2(435);
	while(~scanf("%d%d",&N,&K))
	{
		for (i=0;i<primenum;++i)
		{
			if(prime[i]>N) {num=i;break;}
		}
		memset(fenjie,0,sizeof(fenjie));
		fenjiejiecheng(N,1);
		fenjiejiecheng(K,-1);
		fenjiejiecheng(N-K,-1);

		long long r=1;
		for (i=0;i<num;++i)
		{
			if(fenjie[i]) r*=(fenjie[i]+1);
		}
		printf("%I64d\n",r);
	}

}