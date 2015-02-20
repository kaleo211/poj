#include<stdio.h>
#include<string.h>

char	flaI[11], flaJ[11];
int		sum, count;
int		I[11], J[11];
int		fat[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int	dfs(int  now, int deep) {
	int		i;
	if(deep!=1)		{
		flaI[I[now]] = 'y';	
		flaJ[J[now]] = 'y';

		for(i=now+1; i<count; i++) {
			if(flaI[I[i]]=='n' && flaJ[J[i]]=='n')
				dfs(i, deep-1);
		}

		flaI[I[now]] = 'n';
		flaJ[J[now]] = 'n';
	}
	else sum++;
	return 1;
}

int main () {
	int		i, j, n, k;
	char	a;

	while(scanf("%d %d", &n, &k) && (n!=-1)) {
		count = 0;
		scanf("%c", &a);
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				scanf("%c", &a);
				if(a == '#')	{
					I[count] = i;
					J[count++] = j;
				}
			}
			scanf("%c", &a);
		}

		sum = 0;
		memset(flaI, 'n', sizeof(flaI));
		memset(flaJ, 'n', sizeof(flaJ));

		for(i=0; i<count; i++) 
			dfs(i, k);

		printf("%d\n",sum);
	}
	return 1;
}