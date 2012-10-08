#include <iostream>
#include <string>

using namespace std;
int d[1000][1000];
string a,b;
int max(const int &a,const int &b,const int &c)
{
	int t=a>b?a:b;
	return t>c?t:c;
}

int search(int i,int j)
{
	int q,w,e,t;
	if(i<0||j<0) return 0;
	if(d[i][j]!=-1)
		return d[i][j];

	 if(a[i]==b[j])
		 q=search(i-1,j-1)+1;
	 else
		 q=search(i-1,j-1);
	 w=search(i-1,j);
	 e=search(i,j-1);
	 t=max(q,w,e);
	 d[i][j]=t;
	 return t;
}

int main()
{
	int i,j;
	while(cin>>a)
	{
		cin>>b;
		for(i=0;i<1000;++i)
			for(j=0;j<1000;++j)
				d[i][j]=-1;
		cout<<search(a.size()-1,b.size()-1)<<endl;
	}


}
