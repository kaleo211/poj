#include<stdio.h>

int main() {
	int		i,  num,  t;
	char	pre,   input[1002];
	scanf("%d", &t);
	while(t--) {
		scanf("%s", input);
		pre = input[0];
		num = 1;
		for(i=1; input[i-1]!='\0'; i++) {
			if(input[i]!=pre) {
				printf("%d%c", num,pre);
				num = 1;
				pre = input[i];
			}
			else num++;
		}
		printf("\n");
	}
	return 1;
}