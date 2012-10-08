#include <string.h>
#include <stdio.h>
#define  N 200005

char s[N],s2[N]; // N > 256
int n, sa[N], height[N], rank[N], tmp[N], top[N];
void makesa(){ // O(N * log N)
	int i, j, len, na;
	na = (n < 256 ? 256 : n);
	memset(top, 0, na * sizeof(int));
	for (i = 0; i < n ; i++) top[ rank[i] = s[i] & 0xff ]++;
	for (i = 1; i < na; i++) top[i] += top[i - 1];
	for (i = 0; i < n ; i++) sa[ --top[ rank[i] ] ] = i;
	for (len = 1; len < n; len <<= 1) {
		for (i = 0; i < n; i++) {
			j = sa[i] - len; if (j < 0) j += n;
			tmp[ top[ rank[j] ]++ ] = j;
		}
		sa[ tmp[ top[0] = 0 ] ] = j = 0;
		for (i = 1; i < n; i++) {
			if (rank[ tmp[i] ] != rank[ tmp[i-1] ] ||
				rank[ tmp[i]+len ]!=rank[ tmp[i-1]+len ])
				top[++j] = i;
			sa[ tmp[i] ] = j;
		}
		memcpy(rank, sa , n * sizeof(int));
		memcpy(sa , tmp, n * sizeof(int));
		if (j >= n - 1) break;
	}
}
void lcp(){ // O(4 * N)
	int i, j, k;
	for (j = rank[height[i=k=0]=0]; i < n - 1; i++, k++)
		while (k >= 0 && s[i] != s[ sa[j-1] + k ])
			height[j] = (k--), j = rank[ sa[j] + 1 ];
}

int main()
{
	int olen;
	scanf("%s",s);
	olen=strlen(s);
	scanf("%s",s2);
	strcat(s,"#");
	strcat(s,s2);
	n=strlen(s)+1;
	makesa();
	lcp();

	int i,longest=0;

	for(i=2;i<n;++i)
	{
		if (height[i]>longest && ((sa[i-1]<olen && sa[i]>=olen)||(sa[i-1]>=olen && sa[i]<olen)))
		{
			longest=height[i];
		}
	}
	printf("%d\n",longest);
	return 0;
	
}