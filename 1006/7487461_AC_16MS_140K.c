#include <stdio.h>

int main() { 
	int		q,i,e,c,r,Days=0;

	while(1)	{
		scanf("%d %d %d %d",&q,&i,&e,&c);

		if(q==-1&&i==-1&&e==-1&&c==-1)
			break;

		r = (5544*q + 14421*i + 1288*e - c + 21252)%21252;

		if(!r)
			r = 21252;

		printf("Case %d: the next triple peak occurs in %d days.\n",++Days,r);
	}
	return 0;
} 