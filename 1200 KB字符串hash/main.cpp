#include <stdio.h>
#include <string.h>
#include <math.h>
int hash[256];
char S[16000005];
bool steped[16000005];
int N,NC;

int main()
{
	int i=0,base,num=0,len,tmp;

	scanf("%d%d",&N,&NC);
	scanf("%s",S);
	len=strlen(S);
	base=pow(NC+0.0,N-1.0)+0.1;

	tmp=NC;
	while(tmp)
	{
		if(!hash[S[i]]) hash[S[i]]=--tmp;
		++i;
	}
	for(i=0;i<N;++i)
	{
		 num*=NC;
		 num+=hash[S[i]];
	}
	steped[num]=true;
	for(i=N;i<len;++i)
	{
		num%=base;
		num*=NC;
		num+=hash[S[i]];
		steped[num]=true;
	}
	num=0;
	for(i=0;i<base*NC;++i)
	{
		if(steped[i]) num++;
	}
	printf("%d\n",num);
}
