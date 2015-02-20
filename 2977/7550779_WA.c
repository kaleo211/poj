#include<stdio.h>

int main() {
	int		x, y, z, lx, ly, lz, max, sum;
	while(scanf("%d %d %d %d %d %d",&lx,&ly,&lz,&x,&y,&z) && !(lx==0&&ly==0&&lz==0)) {
		max = x>y?x:y;
		max = max>z?max:z;
		sum = x+y+z-max;
		printf("%d\n",max*max+sum*sum);
	}
	return 1;
}