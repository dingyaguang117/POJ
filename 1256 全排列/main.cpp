#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const char &a,const char &b)
{
	if (a<='z' && b<='z' && a>='a' && b>='a')
	{
		return a<b;
	}
	if (a<='Z' && b<='Z' && a>='A' && b>='A')
	{
		return a<b;
	}
	if (a<='z' && b<='Z' && a>='a' && b>='A')
	{
		return a+('Z'-'z')<b;
	}
	if (a<='Z' && b<='z' && a>='A' && b>='a')
	{
		if(a+('z'-'Z')==b) return true;
		return a+('z'-'Z')<b;
	}
}

int main()
{
	int N;
	char s[15];
	cin>>N;
	while (N--)
	{
		cin>>s;

		int len=strlen(s);
		sort(s,s+len,cmp);
		cout<<s<<endl;
		while (next_permutation(s,s+len,cmp))
		{
			cout<<s<<endl;
		}
	}
}