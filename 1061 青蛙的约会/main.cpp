#include <iostream>

using namespace std;

__int64 gcd(__int64 a,__int64 b)
{
    __int64 t;
	if (!a || !b)
	{
		return 1;
	}
    while (a%b)
    {
        t=a;
        a=b;
        b=t%b;
    }
    return b;
}
__int64 x,y;

void extend_Eulid(__int64 a,__int64 b)
{
	
	__int64 x2,y2,tx,ty,l;
	x=1;y=0;
	x2=0;y2=1;
	do 
	{
		tx=x-a/b*x2;
		ty=y-a/b*y2;
		x=x2;y=y2;
		x2=tx;y2=ty;
		tx=a%b;a=b;b=tx;

	} while (b);
}

int main()
{
    __int64 x1,y1,m,n,L,a,b,d;
    cin>>x1>>y1>>m>>n>>L;
    a=L;
    b=n-m;
    d=x1-y1;
    if(d%gcd(a,b) || b==0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
	//cin>>a>>b;
    extend_Eulid(a,b);

	__int64 g=gcd(a,b);
	__int64 rate=L/g;
	y*=d/g;

	if (y>=0)
	{
		y%=rate;
	}else
	{
		y%=rate;
		y+=rate;
	}

    cout<<y<<endl;
}
