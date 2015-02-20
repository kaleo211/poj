#include<stdio.h>
#include<math.h>
#include<string.h>

bool exist[3005];

int main() {
	int		n, is, i, pre, now;
	while(scanf("%d", &n)!=EOF) {
		memset(exist, 0, sizeof(exist));
		is = 1;
		scanf("%d", &pre);
		for(i=1; i<n; i++) {
			scanf("%d", &now);
			if( abs(now-pre)>=n )
				is = 0;
			else
				exist[abs(now-pre)] = true;
			pre = now;
		}
		for(i=1; i<n; i++)
			if(!exist[i]) {
				is = 0;
				break;
			}
		if(is)
			printf("Jolly\n");
		else
			printf("Not Jolly\n");
	}
	return 0;
}