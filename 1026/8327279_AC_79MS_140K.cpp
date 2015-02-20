#include<stdio.h>
#include<string.h>
int main() {
	int		i, n, m, now, time, count;
	int		next[200], t[200];
	char		arr[202], arra[202];

	while(scanf("%d", &n) && n) {
		for(i=0; i<n; i++)
			scanf("%d", &next[i]);

			for(i=0; i<n; i++) {		//求循环周期
					count = 1;
					now = next[i] - 1;
					while(1) {
						if(now ==i) {
							t[i] = count;
							break;
						}
						now = next[now] - 1;
						count++;
					}
			}

			while(scanf("%d", &m) && m) {

				getchar();
				gets(arr);
				
				for(i=strlen(arr); i<n; i++)    //补齐空格
					arr[i] = ' ';
				memset(arra, 0, sizeof(arra));
				arr[n] = arra[n] =  '\0';

				for(i=0; i<n; i++) {
					now = i;
					int	count = m % t[i];
					for(int j=0;  j<count;  j++) {
						now = next[now] - 1;
					}
					arra[now] = arr[i];
				}
				printf("%s\n", arra);
			}
			printf("\n");
	}
	return 0;
}