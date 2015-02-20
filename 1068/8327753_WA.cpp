#include<stdio.h>
#include<string.h>
int main() {
	int		i, n, j, m, t;
	bool		print, sign[20], used[20];
	scanf("%d", &t);
	while(t--) {
		print = 0;
		memset(sign, 0, sizeof(sign));
		memset(used, 0, sizeof(used));
		scanf("%d", &n);

		for(i=0; i<n; i++) {			//转化成原格式
			scanf("%d", &m);
			for( j=0; ;) {
				if(!sign[j++]) 
					m--;
				if(!m && !sign[j])
					break;
			}
			sign[j] = 1;
		}

		for(i=0; i<20; i++) {		 //转化成W格式
			if(sign[i]) { 
				int	count=1;
				for(j=i-1; ; j--) {
					if(!sign[j] && !used[j]) {
						used[j] = 1;
						break;
					}
					else if(sign[j])
						count++;
				}
				if(print) printf(" ");
				print = 1;
				printf("%d", count);
			}
		}
		printf("\n");
	}
	return 0;
}