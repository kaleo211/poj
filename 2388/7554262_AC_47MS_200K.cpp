#include<stdio.h>
#include<algorithm>
using namespace std;
int cmp(int a, int b) {
	return a>b;
}

int main() {
	int		i,  n,  num[10000];
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &num[i]);
	sort(num, num+n, cmp);
	printf("%d\n", num[n/2]);
	return 1;
}