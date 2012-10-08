#include <iostream>

using namespace  std;


int main()
{
	int n,r,num;
	while(cin>>n)
	{
		r=1;
		num=1;
		while ((r%=n)!=0)
		{
			r=(10*r+1);
			num++;
		}
		cout<<num<<endl;
	}
}