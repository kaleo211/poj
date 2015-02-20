#include<stdio.h>
#include<string.h>
int		parent[100000];

int	find(int x) {
	while(parent[x]!=-1) 
		x = parent[x];
	return x;
}

int main() {
	int		a,  b,  C=1,   i, isTree, flag;
	
	while(scanf("%d %d", &a, &b) && a!=-1) {
		memset(parent, -1, sizeof(parent));

		if(a==0)	{
			printf("Case %d is a tree.\n", C++);
			continue;
		}
		
		isTree = 1;
		parent[b] = a;
		if(a==b) isTree = 0;
		
		while(scanf("%d %d", &a, &b) && a) {
			if(parent[b]==-1 && a!=b)
				parent[b] = a;
			else	
				isTree = 0;
		}
		if(isTree==0) {
			printf("Case %d is not a tree.\n", C++);
			continue;
		}


		for(i=1; ; i++) 
			if(parent[i]!=-1)  {
				flag=i;
				break;
			}
		parent[flag] = find(flag);
		for(i=1; i<100000; i++) {
			if(parent[i]!=-1) {
				parent[i] = find(i);
				if(parent[i]!=parent[flag]) isTree=0;
			}
		}
		if(isTree)		printf("Case %d is a tree.\n", C++);
		else			printf("Case %d is not a tree.\n", C++);
	}
	return 1;
}