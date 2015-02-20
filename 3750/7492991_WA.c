#include<stdio.h>

struct person {
	char	name[17];
	int		next;
};

int	main () {
	int		n, w, s, next, count, i;
	struct person save[65];
		
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%s", save[i].name);
		save[i].next = i+1;
	}
	save[n].next = 1;
	scanf("%d,%d", &w, &s);

	count = n-1;
	while(count--) {
		for(i=1; i<s-1; i++)
			w = save[w].next;
		printf("%s\n", save[save[w].next].name);

		next = save[save[w].next].next;
		save[w].next = next;
		w = next;
	}
	printf("%s\n",save[w].name);
	return 1;
}