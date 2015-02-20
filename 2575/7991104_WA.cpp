#include<stdio.h>
#include<math.h>

int main() {
	int		n, is, i, pre, now;
	while(scanf("%d", &n)!=EOF) {
		is = 1;
		scanf("%d", &pre);
		for(i=1; i<n; i++) {
			scanf("%d", &now);
			if( abs(now-pre)>=n )
				is = 0;
			pre = now;
		}
		if(is)
			printf("Jolly\n");
		else
			printf("Not Jolly\n");
	}
	return 0;
}