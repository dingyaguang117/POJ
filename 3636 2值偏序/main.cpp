#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <bitset>
using namespace std;
 
struct Pair
{
    int a,b;
};
 
int N;
Pair A[20001];
bitset<20001> steped;
 
bool cmp(const Pair &a,const Pair &b)
{
    if (a.a==b.a)
    {
        return a.b<b.b;
    }
    return a.a<b.a;
}
 
int main()
{
    int T,i,j,num,count=0;
    Pair one; 
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for (i=0;i<N;++i)
        {
            scanf("%d%d",&((A+i)->a),&((A+i)->b));
        }
        sort(A,A+N,cmp);
        //memset(steped,0,sizeof(bool)*N);
		steped.reset();
		num=0;
        count=0;
        while (count!=N)
        {
            one.a=one.b=0;
            for (i=0;i<N;++i)
            {
				if(!steped.test(i) && A[i].a>one.a && A[i].b>one.b)
                {
                    steped.set(i);
                    count++;
                    one.a=A[i].a;
                    one.b=A[i].b;
                }
 
            }
            num++;
        }
        printf("%d\n",num);
    }
}