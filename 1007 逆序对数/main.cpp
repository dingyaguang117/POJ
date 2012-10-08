#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define MAXN 256

#define typev int // type of res
typev ar[MAXN]; // index: 1 ~ N
int lowb(int t) { return t & (-t) ; }
void add(int i, typev v) {
	for ( ; i < MAXN; ar[i] += v, i += lowb(i));
}
typev sum(int i) {
	typev s = 0;
	for ( ; i > 0; s += ar[i], i -= lowb(i));
	return s;
}

struct node
{
	string s;
	int v;
};

int N,M;

int getv(string s)
{
	int r=0,i;
	memset(ar,0,sizeof(ar));

	for(i=0;i<N;++i)
	{
		r+=i-sum(s[i]);
		add(s[i],1);
	}
	
	return r;
}

bool cmp(const node &a,const node &b)
{
	return a.v<b.v;
}


int main()
{
	int i,j;
	vector<node> V;
	node data;
	cin>>N>>M;
	for (i=0;i<M;++i)
	{
		cin>>data.s;
		data.v=getv(data.s);
		V.push_back(data);
	}
	sort(V.begin(),V.end(),cmp);
	for (i=0;i<M;++i)
	{
		cout<<V[i].s<<endl;
	}
	return 0;
}