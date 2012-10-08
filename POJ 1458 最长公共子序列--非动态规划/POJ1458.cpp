#include <iostream>
#include <string>

using namespace std;
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

	 if(a[i]==b[j])
		 q=search(i-1,j-1)+1;
	 else
		 q=search(i-1,j-1);
	 w=search(i-1,j);
	 e=search(i,j-1);
	 t=max(q,w,e);
	 return t;
}

int main()
{
	int i,j;
	while(cin>>a)
	{
		cin>>b;
		cout<<search(a.size()-1,b.size()-1)<<endl;
	}


}
