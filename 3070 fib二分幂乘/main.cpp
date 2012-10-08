#include <cstdio>


#define  LIST_LEN 64
//#define  __int64 int

int MOD_N=10000;
class rect22
{
public:
	int a11,a12,a21,a22;
public:
	rect22():a11(0),a12(0),a21(0),a22(0){}
	rect22(int a,int b,int c,int d):a11(a),a12(b),a21(c),a22(d){};
	rect22 & operator=(const rect22 &b)
	{
		a11=b.a11;
		a12=b.a12;
		a21=b.a21;
		a22=b.a22;
		return *this;
	}
};
rect22 operator*(const rect22 &a,const rect22 &b)
{
	rect22 r;
	r.a11=(a.a11*b.a11+a.a12*b.a21)%MOD_N;
	r.a12=(a.a11*b.a12+a.a12*b.a22)%MOD_N;
	r.a21=(a.a21*b.a11+a.a22*b.a21)%MOD_N;
	r.a22=(a.a21*b.a12+a.a22*b.a22)%MOD_N;
	return r;
}
rect22 ss[LIST_LEN];
void pre_Fib(int mod)
{
	MOD_N=mod;
	int i;
	rect22 a(1,1,1,0),t;
	t=a;
	ss[1]=a;
	for(i=2;i<LIST_LEN;++i)
	{
		t=t*t;
		ss[i]=t;
	}
}
__int64 getFib(__int64 n)
{
	int i,k;
	rect22 sum(1,0,0,1);
	k=0;
	while (n!=0)
	{
		i=n%2;
		++k;
		if (i)
		{
			sum=sum*ss[k];
		}
		n/=2;
	}
	return sum.a12;
}


int main()
{
	int n;
	pre_Fib(10000);
	while (scanf("%d",&n),n>=0)
	{
		printf("%d\n",getFib(n));
	}
}