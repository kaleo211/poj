#include<stdio.h>

__int64		X, Y;

__int64	exGcd(int a, int b) {
	__int64		m, temp;
	if(b==0) {
		X = 1;
		Y = 0;
		return a;
	}
	m = exGcd(b, a%b);
	temp = X;
	X = Y;
	Y = temp - (a/b)*Y;
	return m;
}


int main() {
	__int64		x, y, m, n, L, p, a, b, c, res;

	scanf("%I64d %I64d %I64d %I64d %I64d", &x, &y, &m, &n, &L);

	a = m - n;
	b = L;
	c = y - x;
	if(a<0) {a = -a; c = -c;}

	p = exGcd(a,b);

	if(c%p!=0 || m==n) printf("Impossible\n");
	else {
		b /= p;
		c /= p;
		res = c*X % b;
		if(res<0) res += b;
		printf("%I64d\n",res);
	}

	return 1;
}