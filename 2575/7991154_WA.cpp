#include<stdio.h>
#include<math.h>
#include<string.h>

bool exist[3005];

int main() {
	int		n,  i, pre, now;

	while(scanf("%d", &n)!=EOF) {

		memset(exist, 0, sizeof(exist));
		scanf("%d", &pre);
		for(i=1; i<n; i++) {
			scanf("%d", &now);
			exist[abs(now-pre)] = true;
			pre = now;
		}

		for(i=1; i<n; i++)
			if(!exist[i])
				break;

		if(i==n)
			printf("Jolly\n");
		else
			printf("Not Jolly\n");
	}
	return 0;
}