/*
已知二叉树的先序和中序
推出二叉树的结构 并且输出后序

POJ2255
dingyaguang117	2255	Accepted	148K	0MS	C++	769B	2011-04-16 14:45:24

Sample Input

DBACEGF ABCDEFG
BCAD CBAD

Sample Output

ACBFGED
CDAB

*/
#include <stdio.h>
#include <string.h>
struct node
{
	char c;
	node *L,*R;
	node():L(NULL),R(NULL){}
};
char S1[27],S2[27];

void build(node **Root,int a,int b,int a2,int b2)
{
	if (a>b || a2>b2)
	{
		return;
	}
	*Root=new node;
	(*Root)->c=S1[a];
	int p,i;
	for (i=a2;i<=b2;++i)
	{
		if (S2[i]==S1[a])
		{
			p=i;
			break;
		}
	}
	build(&((*Root)->L),a+1,a+p-a2,a2,p-1);
	build(&((*Root)->R),a+p-a2+1,b,p+1,b2);
}

void postorder(node * root)
{
	if (root==NULL)
	{
		return;
	}
	postorder(root->L);
	postorder(root->R);
	printf("%c",root->c);
	delete root;
}

int main()
{

	while (~scanf("%s%s",S1,S2))
	{
		node *Root;
		build(&Root,0,strlen(S1)-1,0,strlen(S2)-1);
		postorder(Root);
		printf("\n");
	}
}