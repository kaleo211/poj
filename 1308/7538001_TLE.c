#include<stdio.h>
#include<string.h>
int		parent[100000], visit[100000];

int	find(int x) {
	while(parent[x]!=x) x = parent[x];
	return x;
}

int main() {
	int		a,  b,  C=0,  max,  i, isTree, flag;
	
	while(scanf("%d %d", &a, &b) && a!=-1) {
		for(i=1; i<100000; i++)
			parent[i] = i;
		memset(visit, 0, sizeof(visit));

		if(a==0)	{
			printf("Case %d is not a tree.\n", C++);
			continue;
		}
		
		max = 0;
		visit[b] = visit[b] = 1;
		if(b>max || a>max)	max = (a>b)?a:b;
		
		parent[b] = a;
		
		isTree = 1;
		while(scanf("%d %d", &a, &b) && a) {
			visit[b] = visit[b] = 1;
			if(b>max || a>max)	max = (a>b)?a:b;
			if(parent[b]==b)
				parent[b] = a;
			else	
				isTree = 0;
		}
		if(isTree==0) {
			printf("Case %d is not a tree.\n", C++);
			continue;
		}

		for(i=1; ; i++)
			if(visit[i]) {
				flag=i;
				break;
			}
		parent[flag] = find(flag);
		for(i=flag+1; i<=max; i++) {
			if(visit[i]==1) {
				parent[i] = find(i);
				if(parent[i]!=parent[flag]) {
					isTree = 0;
					break;
				}
			}
		}
		if(isTree==0)	printf("Case %d is not a tree.\n", C++);
		else			printf("Case %d is a tree.\n", C++);
	}
	return 1;
}