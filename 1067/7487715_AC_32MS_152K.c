#include<stdio.h>
#include<math.h>
int main() {
	int		a, b, win, temp;
	while(scanf("%d %d", &a, &b)!=EOF) {
		if(a==b || a==0 || b==0) win = 1;
		else {
			if(a>b) {
				temp = a;
				a = b;
				b = temp;
			}

			temp = (b - a) * (1 + sqrt(5)) / 2;
			if(temp == a) win = 0;
			else win = 1;
		}
		printf("%d\n", win);
	}
	return 1;
}